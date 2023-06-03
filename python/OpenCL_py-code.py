import pyopencl as cl
import numpy as np

# Create a context and command queue
ctx = cl.create_some_context()
queue = cl.CommandQueue(ctx)

# Create input arrays
a = np.array([1, 2, 3, 4, 5], dtype=np.int32)
b = np.array([6, 7, 8, 9, 10], dtype=np.int32)

# Create OpenCL buffers for input and output arrays
a_buf = cl.Buffer(ctx, cl.mem_flags.READ_ONLY | cl.mem_flags.COPY_HOST_PTR, hostbuf=a)
b_buf = cl.Buffer(ctx, cl.mem_flags.READ_ONLY | cl.mem_flags.COPY_HOST_PTR, hostbuf=b)
result_buf = cl.Buffer(ctx, cl.mem_flags.WRITE_ONLY, size=a.nbytes)

# Build the OpenCL program
program = cl.Program(ctx, """
    __kernel void sum(__global const int* a, __global const int* b, __global int* result) {
        int i = get_global_id(0);
        result[i] = a[i] + b[i];
    }
    """).build()

# Execute the kernel
program.sum(queue, a.shape, None, a_buf, b_buf, result_buf)

# Read the result back from the OpenCL buffer
result = np.empty_like(a)
cl.enqueue_copy(queue, result, result_buf)

print("Result:", result)

