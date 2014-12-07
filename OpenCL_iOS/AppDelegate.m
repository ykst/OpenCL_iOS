//
//  AppDelegate.m
//  OpenCL_iOS
//
//  Created by Yukishita Yohsuke on H26/12/06.
//  Copyright (c) 平成26年 monadworks. All rights reserved.
//

#include <OpenCL/cl.h>

#import "AppDelegate.h"

#define ERROR(fmt, ...) fprintf(stderr, "ERROR:%s:%s:%d: " fmt,  __BASE_FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define ASSERT(b) ({ int __b = (int)(b); if(!(__b)) { ERROR("failed (%s)\n", #b); abort(); } __b;})

#define CL_CHECK(b) ({ int __b = (int)(b); if((__b) != CL_SUCCESS) { ERROR("CL error: %s -> %d\n", #b, __b); } __b;})

#define DUMP(x) printf(_Generic((x), \
    char *: "%s = %s\n", \
    char [4096]: "%s = %s\n", \
    cl_ulong: "%s = %llu\n", \
    cl_int: "%s = %d\n", \
    cl_uint: "%s = %u\n", \
    size_t: "%s = %zu\n", \
    float: "%s = %f\n", \
    void *: "%s = %p\n", \
    default: "%s = %d\n" \
), #x, x)

#define STRINGIZE(x) #x
#define STRINGIZE2(x) STRINGIZE(x)
#define KERNEL_STRING(text) STRINGIZE2(text)

const char *KernelSource = KERNEL_STRING(
    __kernel void copy(
       __global int* input,
       __global int* output,
       const int count)
    {
        int i = get_global_id(0);
        if (i < count) {
            output[i] = input[i];
        }
    }
);

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    cl_int err;
    size_t cb;

    cl_platform_id platform_id;
    cl_context context;
    
    {
        cl_uint num_platforms;
        CL_CHECK(clGetPlatformIDs(0, 0, &num_platforms));
        DUMP(num_platforms);

        cl_platform_id platforms[num_platforms];
        CL_CHECK(clGetPlatformIDs(num_platforms, platforms, &num_platforms));

        platform_id = platforms[0];
        
        cl_context_properties prop[] = {
            CL_CONTEXT_PLATFORM,
            (cl_context_properties) platform_id,
            0
        };

        ASSERT((context = clCreateContextFromType(prop, CL_DEVICE_TYPE_DEFAULT, NULL, NULL, &err)) != NULL);
    }

    {
        char platform_version[4096] = {};
        clGetPlatformInfo (platform_id,  CL_PLATFORM_VERSION,
                           sizeof(platform_version), platform_version, 0);
        DUMP(platform_version);
    }

    {
        char platform_name[4096] = {};
        clGetPlatformInfo (platform_id,  CL_PLATFORM_NAME,
                           sizeof(platform_name), platform_name, 0);
        DUMP(platform_name);
    }

    {
        char platform_profile[4096] = {};
        clGetPlatformInfo (platform_id,  CL_PLATFORM_PROFILE,
                           sizeof(platform_profile), platform_profile, 0);
        DUMP(platform_profile);
    }

    {
        char platform_extensions[4096] = {};
        clGetPlatformInfo (platform_id,  CL_PLATFORM_EXTENSIONS,
                           sizeof(platform_extensions), platform_extensions, 0);
        DUMP(platform_extensions);
    }

    cl_device_id device_id;

    {
        CL_CHECK(clGetContextInfo(context, CL_CONTEXT_DEVICES, 0, NULL, &cb));

        cl_device_id devices[cb / sizeof(cl_device_id)];

        CL_CHECK(clGetContextInfo(context, CL_CONTEXT_DEVICES, cb, devices, 0));

        device_id = devices[0];
    }

    {
        char device_name[4096];
        CL_CHECK(clGetDeviceInfo(device_id, CL_DEVICE_NAME, sizeof(device_name), &device_name, 0));
        DUMP(device_name);
    }

    {
        char device_version[4096];
        CL_CHECK(clGetDeviceInfo(device_id, CL_DEVICE_VERSION, sizeof(device_version), &device_version, 0));
        DUMP(device_version);
    }

    {
        cl_bool device_available;
        CL_CHECK(clGetDeviceInfo(device_id, CL_DEVICE_AVAILABLE, sizeof(cl_bool), &device_available, 0));
        DUMP(device_available);
    }

    {
        cl_bool compiler_available;
        CL_CHECK(clGetDeviceInfo(device_id, CL_DEVICE_AVAILABLE, sizeof(cl_bool), &compiler_available, 0));
        DUMP(compiler_available);
    }

    {
        char device_extensions[4096];
        CL_CHECK(clGetDeviceInfo(device_id, CL_DEVICE_EXTENSIONS, sizeof(device_extensions), &device_extensions, 0));
        DUMP(device_extensions);
    }

    {
        cl_ulong max_constant_buffer_size;
        cl_ulong max_work_group_size;

        CL_CHECK(clGetDeviceInfo(device_id, CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, sizeof(cl_ulong), &max_constant_buffer_size, 0));
        DUMP(max_constant_buffer_size);

        CL_CHECK(clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(cl_ulong), &max_work_group_size, NULL));
        DUMP(max_work_group_size);
    }

    cl_command_queue commands;
    cl_program program;
    cl_kernel kernel;
    cl_mem input, output;
    cl_event event_upload, event_exec, event_download;

    commands = clCreateCommandQueue(context, device_id, CL_QUEUE_PROFILING_ENABLE, &err);

    size_t sizes[1] = { strlen(KernelSource) + 1 };
    program = clCreateProgramWithSource(context, 1, (const char **) &KernelSource, sizes, &err);
    DUMP(err);

    CL_CHECK(clBuildProgram(program, 1, &device_id, NULL, NULL, NULL));

    {
        size_t log_size;

        CL_CHECK(clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size));
        CL_CHECK(err);

        char *build_log = malloc(log_size + 1);

        CL_CHECK(clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, log_size, build_log, NULL));

        build_log[log_size] = '\0';
        DUMP(build_log);

        cl_build_status build_status;
        CL_CHECK(clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_STATUS, sizeof(build_status), &build_status, 0));

        DUMP(build_status);
        free(build_log);
    }



    kernel = clCreateKernel(program, "copy", &err);

    cl_int count = 1024;
    size_t bufflen = sizeof(cl_int) * count;

    CL_CHECK(err);
    input = clCreateBuffer(context,  CL_MEM_READ_WRITE,  bufflen, NULL, &err);
    CL_CHECK(err);
    output = clCreateBuffer(context, CL_MEM_READ_WRITE, bufflen, NULL, &err);
    CL_CHECK(err);

    ASSERT(input != NULL);
    ASSERT(output != NULL);

    srand((unsigned) time(0));

    
    cl_int *results = (cl_int *) malloc(bufflen);
    cl_int *data = (cl_int *) malloc(bufflen);
    for(int i = 0; i < count; i++) {
        data[i] = rand();
    }

    err = clEnqueueWriteBuffer(commands, input, CL_TRUE, 0, bufflen, data, 0, NULL, &event_upload);
    CL_CHECK(err);

    CL_CHECK(clSetKernelArg(kernel, 0, sizeof(cl_mem), &input));
    CL_CHECK(clSetKernelArg(kernel, 1, sizeof(cl_mem), &output));
    CL_CHECK(clSetKernelArg(kernel, 2, sizeof(cl_int), &count));

    size_t global_size[2] = { 1024, 1 };
    size_t local_size[2] = { 1, 1 };
    size_t offsets[2] = { 0, 0 };

    CL_CHECK(clEnqueueNDRangeKernel(commands, kernel, 1, offsets, global_size, local_size, 0, NULL, &event_exec));
    CL_CHECK(clEnqueueReadBuffer( commands, output, CL_TRUE, 0, bufflen, results, 0, NULL, &event_download));

    for(int i = 0; i < count; ++i) {
        ASSERT(results[i] == data[i]);
    }

    printf("Kernel Validation Passed!\n");

    return YES;
}

@end
