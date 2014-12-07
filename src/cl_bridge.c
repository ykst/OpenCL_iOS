/*******************************************************************************
 * Copyright (c) 2008 - 2012 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <OpenCL/cl.h>

/* Platform API */
CL_API_ENTRY cl_int CL_API_CALL
(*clGetPlatformIDs)(cl_uint          /* num_entries */,
                    cl_platform_id * /* platforms */,
                    cl_uint *        /* num_platforms */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetPlatformInfo)(cl_platform_id   /* platform */,
                     cl_platform_info /* param_name */,
                     size_t           /* param_value_size */,
                     void *           /* param_value */,
                     size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

/* Device APIs */
CL_API_ENTRY cl_int CL_API_CALL
(*clGetDeviceIDs)(cl_platform_id   /* platform */,
                  cl_device_type   /* device_type */,
                  cl_uint          /* num_entries */,
                  cl_device_id *   /* devices */,
                  cl_uint *        /* num_devices */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetDeviceInfo)(cl_device_id    /* device */,
                   cl_device_info  /* param_name */,
                   size_t          /* param_value_size */,
                   void *          /* param_value */,
                   size_t *        /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clCreateSubDevices)(cl_device_id                         /* in_device */,
                      const cl_device_partition_property * /* properties */,
                      cl_uint                              /* num_devices */,
                      cl_device_id *                       /* out_devices */,
                      cl_uint *                            /* num_devices_ret */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_int CL_API_CALL
(*clRetainDevice)(cl_device_id /* device */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_int CL_API_CALL
(*clReleaseDevice)(cl_device_id /* device */) CL_API_SUFFIX__VERSION_1_2;

/* Context APIs  */
CL_API_ENTRY cl_context CL_API_CALL
(*clCreateContext)(const cl_context_properties * /* properties */,
                   cl_uint                 /* num_devices */,
                   const cl_device_id *    /* devices */,
                   void (CL_CALLBACK * /* pfn_notify */)(const char *, const void *, size_t, void *),
                   void *                  /* user_data */,
                   cl_int *                /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_context CL_API_CALL
(*clCreateContextFromType)(const cl_context_properties * /* properties */,
                           cl_device_type          /* device_type */,
                           void (CL_CALLBACK *     /* pfn_notify*/ )(const char *, const void *, size_t, void *),
                           void *                  /* user_data */,
                           cl_int *                /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clRetainContext)(cl_context /* context */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clReleaseContext)(cl_context /* context */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetContextInfo)(cl_context         /* context */,
                    cl_context_info    /* param_name */,
                    size_t             /* param_value_size */,
                    void *             /* param_value */,
                    size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

/* Command Queue APIs */
CL_API_ENTRY cl_command_queue CL_API_CALL
(*clCreateCommandQueue)(cl_context                     /* context */,
                        cl_device_id                   /* device */,
                        cl_command_queue_properties    /* properties */,
                        cl_int *                       /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clRetainCommandQueue)(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clReleaseCommandQueue)(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetCommandQueueInfo)(cl_command_queue      /* command_queue */,
                         cl_command_queue_info /* param_name */,
                         size_t                /* param_value_size */,
                         void *                /* param_value */,
                         size_t *              /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

/* Memory Object APIs */
CL_API_ENTRY cl_mem CL_API_CALL
(*clCreateBuffer)(cl_context   /* context */,
                  cl_mem_flags /* flags */,
                  size_t       /* size */,
                  void *       /* host_ptr */,
                  cl_int *     /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_mem CL_API_CALL
(*clCreateSubBuffer)(cl_mem                   /* buffer */,
                     cl_mem_flags             /* flags */,
                     cl_buffer_create_type    /* buffer_create_type */,
                     const void *             /* buffer_create_info */,
                     cl_int *                 /* errcode_ret */) CL_API_SUFFIX__VERSION_1_1;

CL_API_ENTRY cl_mem CL_API_CALL
(*clCreateImage)(cl_context              /* context */,
                 cl_mem_flags            /* flags */,
                 const cl_image_format * /* image_format */,
                 const cl_image_desc *   /* image_desc */,
                 void *                  /* host_ptr */,
                 cl_int *                /* errcode_ret */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_int CL_API_CALL
(*clRetainMemObject)(cl_mem /* memobj */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clReleaseMemObject)(cl_mem /* memobj */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetSupportedImageFormats)(cl_context           /* context */,
                              cl_mem_flags         /* flags */,
                              cl_mem_object_type   /* image_type */,
                              cl_uint              /* num_entries */,
                              cl_image_format *    /* image_formats */,
                              cl_uint *            /* num_image_formats */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetMemObjectInfo)(cl_mem           /* memobj */,
                      cl_mem_info      /* param_name */,
                      size_t           /* param_value_size */,
                      void *           /* param_value */,
                      size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetImageInfo)(cl_mem           /* image */,
                  cl_image_info    /* param_name */,
                  size_t           /* param_value_size */,
                  void *           /* param_value */,
                  size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clSetMemObjectDestructorCallback)(  cl_mem /* memobj */,
                                    void (CL_CALLBACK * /*pfn_notify*/)( cl_mem /* memobj */, void* /*user_data*/),
                                    void * /*user_data */ )             CL_API_SUFFIX__VERSION_1_1;

/* Sampler APIs */
CL_API_ENTRY cl_sampler CL_API_CALL
(*clCreateSampler)(cl_context          /* context */,
                   cl_bool             /* normalized_coords */,
                   cl_addressing_mode  /* addressing_mode */,
                   cl_filter_mode      /* filter_mode */,
                   cl_int *            /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clRetainSampler)(cl_sampler /* sampler */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clReleaseSampler)(cl_sampler /* sampler */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetSamplerInfo)(cl_sampler         /* sampler */,
                    cl_sampler_info    /* param_name */,
                    size_t             /* param_value_size */,
                    void *             /* param_value */,
                    size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

/* Program Object APIs  */
CL_API_ENTRY cl_program CL_API_CALL
(*clCreateProgramWithSource)(cl_context        /* context */,
                             cl_uint           /* count */,
                             const char **     /* strings */,
                             const size_t *    /* lengths */,
                             cl_int *          /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_program CL_API_CALL
(*clCreateProgramWithBinary)(cl_context                     /* context */,
                             cl_uint                        /* num_devices */,
                             const cl_device_id *           /* device_list */,
                             const size_t *                 /* lengths */,
                             const unsigned char **         /* binaries */,
                             cl_int *                       /* binary_status */,
                             cl_int *                       /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_program CL_API_CALL
(*clCreateProgramWithBuiltInKernels)(cl_context            /* context */,
                                     cl_uint               /* num_devices */,
                                     const cl_device_id *  /* device_list */,
                                     const char *          /* kernel_names */,
                                     cl_int *              /* errcode_ret */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_int CL_API_CALL
(*clRetainProgram)(cl_program /* program */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clReleaseProgram)(cl_program /* program */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clBuildProgram)(cl_program           /* program */,
                  cl_uint              /* num_devices */,
                  const cl_device_id * /* device_list */,
                  const char *         /* options */,
                  void (CL_CALLBACK *  /* pfn_notify */)(cl_program /* program */, void * /* user_data */),
                  void *               /* user_data */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clCompileProgram)(cl_program           /* program */,
                    cl_uint              /* num_devices */,
                    const cl_device_id * /* device_list */,
                    const char *         /* options */,
                    cl_uint              /* num_input_headers */,
                    const cl_program *   /* input_headers */,
                    const char **        /* header_include_names */,
                    void (CL_CALLBACK *  /* pfn_notify */)(cl_program /* program */, void * /* user_data */),
                    void *               /* user_data */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_program CL_API_CALL
(*clLinkProgram)(cl_context           /* context */,
                 cl_uint              /* num_devices */,
                 const cl_device_id * /* device_list */,
                 const char *         /* options */,
                 cl_uint              /* num_input_programs */,
                 const cl_program *   /* input_programs */,
                 void (CL_CALLBACK *  /* pfn_notify */)(cl_program /* program */, void * /* user_data */),
                 void *               /* user_data */,
                 cl_int *             /* errcode_ret */ ) CL_API_SUFFIX__VERSION_1_2;


CL_API_ENTRY cl_int CL_API_CALL
(*clUnloadPlatformCompiler)(cl_platform_id /* platform */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetProgramInfo)(cl_program         /* program */,
                    cl_program_info    /* param_name */,
                    size_t             /* param_value_size */,
                    void *             /* param_value */,
                    size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetProgramBuildInfo)(cl_program            /* program */,
                         cl_device_id          /* device */,
                         cl_program_build_info /* param_name */,
                         size_t                /* param_value_size */,
                         void *                /* param_value */,
                         size_t *              /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

/* Kernel Object APIs */
CL_API_ENTRY cl_kernel CL_API_CALL
(*clCreateKernel)(cl_program      /* program */,
                  const char *    /* kernel_name */,
                  cl_int *        /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clCreateKernelsInProgram)(cl_program     /* program */,
                            cl_uint        /* num_kernels */,
                            cl_kernel *    /* kernels */,
                            cl_uint *      /* num_kernels_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clRetainKernel)(cl_kernel    /* kernel */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clReleaseKernel)(cl_kernel   /* kernel */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clSetKernelArg)(cl_kernel    /* kernel */,
                  cl_uint      /* arg_index */,
                  size_t       /* arg_size */,
                  const void * /* arg_value */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetKernelInfo)(cl_kernel       /* kernel */,
                   cl_kernel_info  /* param_name */,
                   size_t          /* param_value_size */,
                   void *          /* param_value */,
                   size_t *        /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetKernelArgInfo)(cl_kernel       /* kernel */,
                      cl_uint         /* arg_indx */,
                      cl_kernel_arg_info  /* param_name */,
                      size_t          /* param_value_size */,
                      void *          /* param_value */,
                      size_t *        /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetKernelWorkGroupInfo)(cl_kernel                  /* kernel */,
                            cl_device_id               /* device */,
                            cl_kernel_work_group_info  /* param_name */,
                            size_t                     /* param_value_size */,
                            void *                     /* param_value */,
                            size_t *                   /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

/* Event Object APIs */
CL_API_ENTRY cl_int CL_API_CALL
(*clWaitForEvents)(cl_uint             /* num_events */,
                   const cl_event *    /* event_list */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clGetEventInfo)(cl_event         /* event */,
                  cl_event_info    /* param_name */,
                  size_t           /* param_value_size */,
                  void *           /* param_value */,
                  size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_event CL_API_CALL
(*clCreateUserEvent)(cl_context    /* context */,
                     cl_int *      /* errcode_ret */) CL_API_SUFFIX__VERSION_1_1;

CL_API_ENTRY cl_int CL_API_CALL
(*clRetainEvent)(cl_event /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clReleaseEvent)(cl_event /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clSetUserEventStatus)(cl_event   /* event */,
                        cl_int     /* execution_status */) CL_API_SUFFIX__VERSION_1_1;

CL_API_ENTRY cl_int CL_API_CALL
(*clSetEventCallback)( cl_event    /* event */,
                      cl_int      /* command_exec_callback_type */,
                      void (CL_CALLBACK * /* pfn_notify */)(cl_event, cl_int, void *),
                      void *      /* user_data */) CL_API_SUFFIX__VERSION_1_1;

/* Profiling APIs */
CL_API_ENTRY cl_int CL_API_CALL
(*clGetEventProfilingInfo)(cl_event            /* event */,
                           cl_profiling_info   /* param_name */,
                           size_t              /* param_value_size */,
                           void *              /* param_value */,
                           size_t *            /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

/* Flush and Finish APIs */
CL_API_ENTRY cl_int CL_API_CALL
(*clFlush)(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clFinish)(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;

/* Enqueued Commands APIs */
CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueReadBuffer)(cl_command_queue    /* command_queue */,
                       cl_mem              /* buffer */,
                       cl_bool             /* blocking_read */,
                       size_t              /* offset */,
                       size_t              /* size */,
                       void *              /* ptr */,
                       cl_uint             /* num_events_in_wait_list */,
                       const cl_event *    /* event_wait_list */,
                       cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueReadBufferRect)(cl_command_queue    /* command_queue */,
                           cl_mem              /* buffer */,
                           cl_bool             /* blocking_read */,
                           const size_t *      /* buffer_offset */,
                           const size_t *      /* host_offset */,
                           const size_t *      /* region */,
                           size_t              /* buffer_row_pitch */,
                           size_t              /* buffer_slice_pitch */,
                           size_t              /* host_row_pitch */,
                           size_t              /* host_slice_pitch */,
                           void *              /* ptr */,
                           cl_uint             /* num_events_in_wait_list */,
                           const cl_event *    /* event_wait_list */,
                           cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_1;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueWriteBuffer)(cl_command_queue   /* command_queue */,
                        cl_mem             /* buffer */,
                        cl_bool            /* blocking_write */,
                        size_t             /* offset */,
                        size_t             /* size */,
                        const void *       /* ptr */,
                        cl_uint            /* num_events_in_wait_list */,
                        const cl_event *   /* event_wait_list */,
                        cl_event *         /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueWriteBufferRect)(cl_command_queue    /* command_queue */,
                            cl_mem              /* buffer */,
                            cl_bool             /* blocking_write */,
                            const size_t *      /* buffer_offset */,
                            const size_t *      /* host_offset */,
                            const size_t *      /* region */,
                            size_t              /* buffer_row_pitch */,
                            size_t              /* buffer_slice_pitch */,
                            size_t              /* host_row_pitch */,
                            size_t              /* host_slice_pitch */,
                            const void *        /* ptr */,
                            cl_uint             /* num_events_in_wait_list */,
                            const cl_event *    /* event_wait_list */,
                            cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_1;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueFillBuffer)(cl_command_queue   /* command_queue */,
                       cl_mem             /* buffer */,
                       const void *       /* pattern */,
                       size_t             /* pattern_size */,
                       size_t             /* offset */,
                       size_t             /* size */,
                       cl_uint            /* num_events_in_wait_list */,
                       const cl_event *   /* event_wait_list */,
                       cl_event *         /* event */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueCopyBuffer)(cl_command_queue    /* command_queue */,
                       cl_mem              /* src_buffer */,
                       cl_mem              /* dst_buffer */,
                       size_t              /* src_offset */,
                       size_t              /* dst_offset */,
                       size_t              /* size */,
                       cl_uint             /* num_events_in_wait_list */,
                       const cl_event *    /* event_wait_list */,
                       cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueCopyBufferRect)(cl_command_queue    /* command_queue */,
                           cl_mem              /* src_buffer */,
                           cl_mem              /* dst_buffer */,
                           const size_t *      /* src_origin */,
                           const size_t *      /* dst_origin */,
                           const size_t *      /* region */,
                           size_t              /* src_row_pitch */,
                           size_t              /* src_slice_pitch */,
                           size_t              /* dst_row_pitch */,
                           size_t              /* dst_slice_pitch */,
                           cl_uint             /* num_events_in_wait_list */,
                           const cl_event *    /* event_wait_list */,
                           cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_1;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueReadImage)(cl_command_queue     /* command_queue */,
                      cl_mem               /* image */,
                      cl_bool              /* blocking_read */,
                      const size_t *       /* origin[3] */,
                      const size_t *       /* region[3] */,
                      size_t               /* row_pitch */,
                      size_t               /* slice_pitch */,
                      void *               /* ptr */,
                      cl_uint              /* num_events_in_wait_list */,
                      const cl_event *     /* event_wait_list */,
                      cl_event *           /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueWriteImage)(cl_command_queue    /* command_queue */,
                       cl_mem              /* image */,
                       cl_bool             /* blocking_write */,
                       const size_t *      /* origin[3] */,
                       const size_t *      /* region[3] */,
                       size_t              /* input_row_pitch */,
                       size_t              /* input_slice_pitch */,
                       const void *        /* ptr */,
                       cl_uint             /* num_events_in_wait_list */,
                       const cl_event *    /* event_wait_list */,
                       cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueFillImage)(cl_command_queue   /* command_queue */,
                      cl_mem             /* image */,
                      const void *       /* fill_color */,
                      const size_t *     /* origin[3] */,
                      const size_t *     /* region[3] */,
                      cl_uint            /* num_events_in_wait_list */,
                      const cl_event *   /* event_wait_list */,
                      cl_event *         /* event */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueCopyImage)(cl_command_queue     /* command_queue */,
                      cl_mem               /* src_image */,
                      cl_mem               /* dst_image */,
                      const size_t *       /* src_origin[3] */,
                      const size_t *       /* dst_origin[3] */,
                      const size_t *       /* region[3] */,
                      cl_uint              /* num_events_in_wait_list */,
                      const cl_event *     /* event_wait_list */,
                      cl_event *           /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueCopyImageToBuffer)(cl_command_queue /* command_queue */,
                              cl_mem           /* src_image */,
                              cl_mem           /* dst_buffer */,
                              const size_t *   /* src_origin[3] */,
                              const size_t *   /* region[3] */,
                              size_t           /* dst_offset */,
                              cl_uint          /* num_events_in_wait_list */,
                              const cl_event * /* event_wait_list */,
                              cl_event *       /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueCopyBufferToImage)(cl_command_queue /* command_queue */,
                              cl_mem           /* src_buffer */,
                              cl_mem           /* dst_image */,
                              size_t           /* src_offset */,
                              const size_t *   /* dst_origin[3] */,
                              const size_t *   /* region[3] */,
                              cl_uint          /* num_events_in_wait_list */,
                              const cl_event * /* event_wait_list */,
                              cl_event *       /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY void * CL_API_CALL
(*clEnqueueMapBuffer)(cl_command_queue /* command_queue */,
                      cl_mem           /* buffer */,
                      cl_bool          /* blocking_map */,
                      cl_map_flags     /* map_flags */,
                      size_t           /* offset */,
                      size_t           /* size */,
                      cl_uint          /* num_events_in_wait_list */,
                      const cl_event * /* event_wait_list */,
                      cl_event *       /* event */,
                      cl_int *         /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY void * CL_API_CALL
(*clEnqueueMapImage)(cl_command_queue  /* command_queue */,
                     cl_mem            /* image */,
                     cl_bool           /* blocking_map */,
                     cl_map_flags      /* map_flags */,
                     const size_t *    /* origin[3] */,
                     const size_t *    /* region[3] */,
                     size_t *          /* image_row_pitch */,
                     size_t *          /* image_slice_pitch */,
                     cl_uint           /* num_events_in_wait_list */,
                     const cl_event *  /* event_wait_list */,
                     cl_event *        /* event */,
                     cl_int *          /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueUnmapMemObject)(cl_command_queue /* command_queue */,
                           cl_mem           /* memobj */,
                           void *           /* mapped_ptr */,
                           cl_uint          /* num_events_in_wait_list */,
                           const cl_event *  /* event_wait_list */,
                           cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueMigrateMemObjects)(cl_command_queue       /* command_queue */,
                              cl_uint                /* num_mem_objects */,
                              const cl_mem *         /* mem_objects */,
                              cl_mem_migration_flags /* flags */,
                              cl_uint                /* num_events_in_wait_list */,
                              const cl_event *       /* event_wait_list */,
                              cl_event *             /* event */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueNDRangeKernel)(cl_command_queue /* command_queue */,
                          cl_kernel        /* kernel */,
                          cl_uint          /* work_dim */,
                          const size_t *   /* global_work_offset */,
                          const size_t *   /* global_work_size */,
                          const size_t *   /* local_work_size */,
                          cl_uint          /* num_events_in_wait_list */,
                          const cl_event * /* event_wait_list */,
                          cl_event *       /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueTask)(cl_command_queue  /* command_queue */,
                 cl_kernel         /* kernel */,
                 cl_uint           /* num_events_in_wait_list */,
                 const cl_event *  /* event_wait_list */,
                 cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueNativeKernel)(cl_command_queue  /* command_queue */,
                         void (CL_CALLBACK * /*user_func*/)(void *),
                         void *            /* args */,
                         size_t            /* cb_args */,
                         cl_uint           /* num_mem_objects */,
                         const cl_mem *    /* mem_list */,
                         const void **     /* args_mem_loc */,
                         cl_uint           /* num_events_in_wait_list */,
                         const cl_event *  /* event_wait_list */,
                         cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_0;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueMarkerWithWaitList)(cl_command_queue /* command_queue */,
                               cl_uint           /* num_events_in_wait_list */,
                               const cl_event *  /* event_wait_list */,
                               cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_2;

CL_API_ENTRY cl_int CL_API_CALL
(*clEnqueueBarrierWithWaitList)(cl_command_queue /* command_queue */,
                                cl_uint           /* num_events_in_wait_list */,
                                const cl_event *  /* event_wait_list */,
                                cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_2;



/* Extension function access
 *
 * Returns the extension function address for the given function name,
 * or NULL if a valid function can not be found.  The client must
 * check to make sure the address is not NULL, before using or
 * calling the returned function address.
 */
CL_API_ENTRY void * CL_API_CALL
(*clGetExtensionFunctionAddressForPlatform)(cl_platform_id /* platform */,
                                            const char *   /* func_name */) CL_API_SUFFIX__VERSION_1_2;


// Deprecated OpenCL 1.1 APIs
CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
(*clCreateImage2D)(cl_context              /* context */,
                   cl_mem_flags            /* flags */,
                   const cl_image_format * /* image_format */,
                   size_t                  /* image_width */,
                   size_t                  /* image_height */,
                   size_t                  /* image_row_pitch */,
                   void *                  /* host_ptr */,
                   cl_int *                /* errcode_ret */);

CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
(*clCreateImage3D)(cl_context              /* context */,
                   cl_mem_flags            /* flags */,
                   const cl_image_format * /* image_format */,
                   size_t                  /* image_width */,
                   size_t                  /* image_height */,
                   size_t                  /* image_depth */,
                   size_t                  /* image_row_pitch */,
                   size_t                  /* image_slice_pitch */,
                   void *                  /* host_ptr */,
                   cl_int *                /* errcode_ret */);

CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
(*clEnqueueMarker)(cl_command_queue    /* command_queue */,
                   cl_event *          /* event */);

CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
(*clEnqueueWaitForEvents)(cl_command_queue /* command_queue */,
                          cl_uint          /* num_events */,
                          const cl_event * /* event_list */);

CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
(*clEnqueueBarrier)(cl_command_queue /* command_queue */);

CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
(*clUnloadCompiler)(void);

CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED void * CL_API_CALL
(*clGetExtensionFunctionAddress)(const char * /* func_name */);


#define ERROR(fmt, ...) fprintf(stderr, "ERROR:%s:%s:%d: " fmt,  __BASE_FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define CHECK(b) ({ int __b = (int)(b); if(!(__b)) { ERROR("failed (%s)\n", #b);  } __b;})

static __attribute__((constructor)) void
__cl_bridge_load_symbols(void)
{
    void *lib = dlopen("/System/Library/PrivateFrameworks/OpenCL.framework/OpenCL", RTLD_LAZY);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    CHECK((clBuildProgram = dlsym(lib, "clBuildProgram")) != NULL);
    //CHECK((clCompileProgram = dlsym(lib, "clCompileProgram")) != NULL);
    CHECK((clCreateBuffer = dlsym(lib, "clCreateBuffer")) != NULL);
    CHECK((clCreateCommandQueue = dlsym(lib, "clCreateCommandQueue")) != NULL);
        //CHECK((clCreateCommandQueueWithPropertiesAPPLE = dlsym(lib, "clCreateCommandQueueWithPropertiesAPPLE")) != NULL);
    CHECK((clCreateContext = dlsym(lib, "clCreateContext")) != NULL);
    CHECK((clCreateContextFromType = dlsym(lib, "clCreateContextFromType")) != NULL);
    //CHECK((clCreateImage = dlsym(lib, "clCreateImage")) != NULL);
    CHECK((clCreateImage2D = dlsym(lib, "clCreateImage2D")) != NULL);
    CHECK((clCreateImage3D = dlsym(lib, "clCreateImage3D")) != NULL);
    CHECK((clCreateKernel = dlsym(lib, "clCreateKernel")) != NULL);
    CHECK((clCreateKernelsInProgram = dlsym(lib, "clCreateKernelsInProgram")) != NULL);
    CHECK((clCreateProgramWithBinary = dlsym(lib, "clCreateProgramWithBinary")) != NULL);
    CHECK((clCreateProgramWithBuiltInKernels = dlsym(lib, "clCreateProgramWithBuiltInKernels")) != NULL);
    CHECK((clCreateProgramWithSource = dlsym(lib, "clCreateProgramWithSource")) != NULL);
    CHECK((clCreateSampler = dlsym(lib, "clCreateSampler")) != NULL);
    CHECK((clCreateSubBuffer = dlsym(lib, "clCreateSubBuffer")) != NULL);
    CHECK((clCreateSubDevices = dlsym(lib, "clCreateSubDevices")) != NULL);
    CHECK((clCreateUserEvent = dlsym(lib, "clCreateUserEvent")) != NULL);
    CHECK((clEnqueueBarrier = dlsym(lib, "clEnqueueBarrier")) != NULL);
    CHECK((clEnqueueBarrierWithWaitList = dlsym(lib, "clEnqueueBarrierWithWaitList")) != NULL);
    CHECK((clEnqueueCopyBuffer = dlsym(lib, "clEnqueueCopyBuffer")) != NULL);
    CHECK((clEnqueueCopyBufferRect = dlsym(lib, "clEnqueueCopyBufferRect")) != NULL);
    CHECK((clEnqueueCopyBufferToImage = dlsym(lib, "clEnqueueCopyBufferToImage")) != NULL);
    CHECK((clEnqueueCopyImage = dlsym(lib, "clEnqueueCopyImage")) != NULL);
    CHECK((clEnqueueCopyImageToBuffer = dlsym(lib, "clEnqueueCopyImageToBuffer")) != NULL);
    CHECK((clEnqueueFillBuffer = dlsym(lib, "clEnqueueFillBuffer")) != NULL);
    CHECK((clEnqueueFillImage = dlsym(lib, "clEnqueueFillImage")) != NULL);
    CHECK((clEnqueueMapBuffer = dlsym(lib, "clEnqueueMapBuffer")) != NULL);
    CHECK((clEnqueueMapImage = dlsym(lib, "clEnqueueMapImage")) != NULL);
    CHECK((clEnqueueMarker = dlsym(lib, "clEnqueueMarker")) != NULL);
    CHECK((clEnqueueMarkerWithWaitList = dlsym(lib, "clEnqueueMarkerWithWaitList")) != NULL);
    CHECK((clEnqueueMigrateMemObjects = dlsym(lib, "clEnqueueMigrateMemObjects")) != NULL);
    CHECK((clEnqueueNDRangeKernel = dlsym(lib, "clEnqueueNDRangeKernel")) != NULL);
    CHECK((clEnqueueNativeKernel = dlsym(lib, "clEnqueueNativeKernel")) != NULL);
    CHECK((clEnqueueReadBuffer = dlsym(lib, "clEnqueueReadBuffer")) != NULL);
    CHECK((clEnqueueReadBufferRect = dlsym(lib, "clEnqueueReadBufferRect")) != NULL);
    CHECK((clEnqueueReadImage = dlsym(lib, "clEnqueueReadImage")) != NULL);
    CHECK((clEnqueueTask = dlsym(lib, "clEnqueueTask")) != NULL);
    CHECK((clEnqueueUnmapMemObject = dlsym(lib, "clEnqueueUnmapMemObject")) != NULL);
    CHECK((clEnqueueWaitForEvents = dlsym(lib, "clEnqueueWaitForEvents")) != NULL);
    CHECK((clEnqueueWriteBuffer = dlsym(lib, "clEnqueueWriteBuffer")) != NULL);
    CHECK((clEnqueueWriteBufferRect = dlsym(lib, "clEnqueueWriteBufferRect")) != NULL);
    CHECK((clEnqueueWriteImage = dlsym(lib, "clEnqueueWriteImage")) != NULL);
    CHECK((clFinish = dlsym(lib, "clFinish")) != NULL);
    CHECK((clFlush = dlsym(lib, "clFlush")) != NULL);
    CHECK((clGetCommandQueueInfo = dlsym(lib, "clGetCommandQueueInfo")) != NULL);
    CHECK((clGetContextInfo = dlsym(lib, "clGetContextInfo")) != NULL);
    CHECK((clGetDeviceIDs = dlsym(lib, "clGetDeviceIDs")) != NULL);
    CHECK((clGetDeviceInfo = dlsym(lib, "clGetDeviceInfo")) != NULL);
    CHECK((clGetEventInfo = dlsym(lib, "clGetEventInfo")) != NULL);
    CHECK((clGetEventProfilingInfo = dlsym(lib, "clGetEventProfilingInfo")) != NULL);
    CHECK((clGetExtensionFunctionAddress = dlsym(lib, "clGetExtensionFunctionAddress")) != NULL);
    CHECK((clGetExtensionFunctionAddressForPlatform = dlsym(lib, "clGetExtensionFunctionAddressForPlatform")) != NULL);
    CHECK((clGetImageInfo = dlsym(lib, "clGetImageInfo")) != NULL);
    CHECK((clGetKernelArgInfo = dlsym(lib, "clGetKernelArgInfo")) != NULL);
    CHECK((clGetKernelInfo = dlsym(lib, "clGetKernelInfo")) != NULL);
    CHECK((clGetKernelWorkGroupInfo = dlsym(lib, "clGetKernelWorkGroupInfo")) != NULL);
    CHECK((clGetMemObjectInfo = dlsym(lib, "clGetMemObjectInfo")) != NULL);
    CHECK((clGetPlatformIDs = dlsym(lib, "clGetPlatformIDs")) != NULL);
    CHECK((clGetPlatformInfo = dlsym(lib, "clGetPlatformInfo")) != NULL);
    CHECK((clGetProgramBuildInfo = dlsym(lib, "clGetProgramBuildInfo")) != NULL);
    CHECK((clGetProgramInfo = dlsym(lib, "clGetProgramInfo")) != NULL);
    CHECK((clGetSamplerInfo = dlsym(lib, "clGetSamplerInfo")) != NULL);
    CHECK((clGetSupportedImageFormats = dlsym(lib, "clGetSupportedImageFormats")) != NULL);
    CHECK((clLinkProgram = dlsym(lib, "clLinkProgram")) != NULL);
    CHECK((clReleaseCommandQueue = dlsym(lib, "clReleaseCommandQueue")) != NULL);
    CHECK((clReleaseContext = dlsym(lib, "clReleaseContext")) != NULL);
    CHECK((clReleaseDevice = dlsym(lib, "clReleaseDevice")) != NULL);
    CHECK((clReleaseEvent = dlsym(lib, "clReleaseEvent")) != NULL);
    CHECK((clReleaseKernel = dlsym(lib, "clReleaseKernel")) != NULL);
    CHECK((clReleaseMemObject = dlsym(lib, "clReleaseMemObject")) != NULL);
    CHECK((clReleaseProgram = dlsym(lib, "clReleaseProgram")) != NULL);
    CHECK((clReleaseSampler = dlsym(lib, "clReleaseSampler")) != NULL);
    CHECK((clRetainCommandQueue = dlsym(lib, "clRetainCommandQueue")) != NULL);
    CHECK((clRetainContext = dlsym(lib, "clRetainContext")) != NULL);
    CHECK((clRetainDevice = dlsym(lib, "clRetainDevice")) != NULL);
    CHECK((clRetainEvent = dlsym(lib, "clRetainEvent")) != NULL);
    CHECK((clRetainKernel = dlsym(lib, "clRetainKernel")) != NULL);
    CHECK((clRetainMemObject = dlsym(lib, "clRetainMemObject")) != NULL);
    CHECK((clRetainProgram = dlsym(lib, "clRetainProgram")) != NULL);
    CHECK((clRetainSampler = dlsym(lib, "clRetainSampler")) != NULL);
    CHECK((clSetEventCallback = dlsym(lib, "clSetEventCallback")) != NULL);
    CHECK((clSetKernelArg = dlsym(lib, "clSetKernelArg")) != NULL);
    CHECK((clSetMemObjectDestructorCallback = dlsym(lib, "clSetMemObjectDestructorCallback")) != NULL);
    CHECK((clSetUserEventStatus = dlsym(lib, "clSetUserEventStatus")) != NULL);
    CHECK((clUnloadCompiler = dlsym(lib, "clUnloadCompiler")) != NULL);
    CHECK((clUnloadPlatformCompiler = dlsym(lib, "clUnloadPlatformCompiler")) != NULL);
    CHECK((clWaitForEvents = dlsym(lib, "clWaitForEvents")) != NULL);
#pragma GCC diagnostic pop

}
