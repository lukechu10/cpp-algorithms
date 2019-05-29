FROM gitpod/workspace-full-vnc

RUN apt-get update \
	&& sudo apt-get install gdb