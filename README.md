c-skills
========
Provide input to the 'naive' application, such that it will spawn a new shell.

In order to provide as input the actual byte array of your solution and not the
ascii representations of each character, you can pass the input as follows:

  - ./naive `./shellcode.sh`

Where shellcode.sh is created, for example, by:

  - echo printf \"Hello-World\" > shellcode.sh
  - chmod 755 shellcode.sh

