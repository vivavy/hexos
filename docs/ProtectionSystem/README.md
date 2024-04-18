# HexOS protection system

# Preventing access to the kernel

Access to the kernel is prevented by x86_64 built in protection system.

# Preventing access to system files

Access to system files is prevented by ramdisk system.
Let me explain how it works.
The ramdisk system is a system that allows to mount a file system on a memory address.
So, for each process mounts a file system on a memory address.
And then, the process can access the file system.
But, the directory /sys being not mounted on a memory address, so, the process can't access the file system.

# Preventing access to user files

This one works in the same way as the ramdisk system with a little difference.
The difference is that the user files are mounted on a memory address ONLY if user premitted to access user files.
Also, the user files are mounted on a memory address if the process is a part of a package that has user premitted to access user files.

# Preventing access to other processes

If process A wants to access memory of process B, it sends a request to the kernel.
The kernel sends the request to the process B, and process B handles the request and sends a response to the kernel.
The kernel sends the response to the process A.
So, the process A can't access the memory of the process B without the process B's permission.
In request, the process A can send any data to the process B to identify itself.
In response, the process B can send any data to the process A (for instance to find permitted memory).
if process B sends negative response, the process A can't access the memory of the process B.
if process B sends positive response, the process A can access the memory of the process B (but only memory SHARED with the process B).
To share memory, the process B must send a request to the kernel to share the memory with the process A.
The kernel changes the memory permissions of the process B to allow the process A to access the memory of the process B.

# Preventing executing dangerous binaries

Firstly, you can't execute just any binary.
To execute a binary, it must be a part of a package.
And the package must be signed by a trusted key.
So, the process can't execute a binary that is not a part of a package.
Secondly, you can't execute a binary that is not signed by a checksum.
So, the process can't execute a binary that is not signed by a checksum.

# Preventing access to system functions

You can't access system functions without access key.

To get access key, process need to send request to the kernel.
The kernel reads permissions of a package and returns access key.

# Preventing faking of trusted keys

You can't fake trusted keys because they stored on shared network storage.
To be able to install packages without internet connections, system periodically checks data in shared network storage.
If trusted key of package is not stored on shared network storage, package can't be installed.

# Getting trusted key

To get trusted key, you need to fill a form on a website of HexOS*.
Next, wait from 5 to 10 minutes and your key will be sent to your ViIS** Account.
Now, you can sign your package with your trusted key.

# Notes

*HexOS website, coming soon, now you will be able to register through telegram.

**ViIS (Vi Infrastructure) is a project of Ivan Chetchasov, coming not soon, so you will get your key through telegram.
