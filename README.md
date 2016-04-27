##Systems Software Semester Project

Hey guys, I'm new to Git so this is going to be a learning experience. We'll use this to collaborate on this project. I'll post the instructions below for reference.


###Overview:
In this project you will implement a simple UNIX-like shell environment and file system with a hierarchical directory structure. Your file system should be stored in main memory and should allow users to browse the directory structure, create and delete files and directories, etc. File contents need not be supported. The file system emulates a Unix file system environment through an interactive shell for the user. Specifically, you are required to implement several shell commands to allow interactive use

###Shell Commands:
Below is a list of shell commands that you need to support in your file system. We will test your system using the following commands. You may add more for your own purpose, but keep the format of the required commands.

**mkfs** - Make a new file system: format the memory disk so that it is ready for other system operations. When this command is executed, all existing contents of the file system should be deleted.

**mkdir <dirname>** - Create a sub-directory <dirname> under the current directory. Report an error if the file or directory <dirname> already exists.

*Example: mkdir foo*

**rmdir <dirname>** - Remove the sub-directory <dirname>. A directory cannot be removed if it is not empty. Also report an error if the directory <dirname> does not exist or is a file instead of directory.

*Example: rmdir foo*

**cd <dirname>** - Change the current directory to <dirname>. You need to support changing current dir to a child dir or the parent dir of the current directory. All other current directory changes are optional. Report an error if the destination directory does not exist.

*Example: cd bar (go to the child dir “bar”)*

*cd .. (go to the parent dir)*

*cd ../../foo/bar (this is optional)*

*cd foo/bar (this is optional)*

**stat <name>** - Show the status of the file or directory with name <name>. It should display the creation time of this file/directory. Output directory names should be enclosed in square brackets. Report an error if file or directory <name> does not exist.

*Example: stat foo*

**ls** - Show the contents of the current directory. No parameters need to be supported. Output directory names should be enclosed in square brackets.

**mkfile <filename>** - Create a file <filename> under the current directory. Report an error if the file or directory <filename> already exists.

*Example: mkfile foo*

**rmfile <filename>** - Remove a file <filename> under the current directory. Report an error if the file <filename> does not exist. Also report an error if <filename> is a directory instead of a file.

*Example: rmfile foo*

**exit** - Exit your shell file system and return control to operating system shell.

###Extra credit: (20 points)
Implement the above optional cd parts (change current directory to arbitrary destination directory). Report an error if the destination directory does not exist.

###Grading:
1. Design document must be submitted with your source codes. It should specify all implemented commands. It should specify the main data structures and algorithms you used for your program. Also specify briefly what each member of your group implemented or contributed.
2. The source codes with a makefile. Your program should be written in C or C++.

###Testing:
We will use a testing script containing a list of shell commands to test your program. It will be tested in the Ubuntu environment.

###Sample running of your shell file system (assume your shell file system is called <MyFileSys>):
```
Ubuntu_shell_prompt> <MyFileSys>
Welcome to CSCI 3232 shell file system!
My_shell_prompt>mkfs
OK, file system formatted and ready for use!
My_shell_prompt>mkdir food
OK, [food] successfully created at 10:20:59, 01/01/2016
My_shell_prompt>mkfile egg
OK, egg successfully created at 10:25:59, 01/01/2016
My_shell_prompt>ls
[food] egg
My_shell_prompt>rmfile apple
Error, file apple does not exist!
My_shell_prompt>cd food
OK, current directory is /food/
My_shell_prompt>mkfile peach
OK, peach successfully created at 10:27:59, 01/01/2016
My_shell_prompt>cd ..
OK, current directory is /
My_shell_prompt>rmdir food
Error, [food] is not empty
My_shell_prompt>stat egg
egg was created at 10:25:59, 01/01/2016
My_shell_prompt>stat food
[food] was created at 10:20:59, 01/01/2016
My_shell_prompt>mkfs
OK, file system formatted and ready for use!
My_shell_prompt>ls
My_shell_prompt>exit
Bye!
Ubuntu_shell_prompt>
```