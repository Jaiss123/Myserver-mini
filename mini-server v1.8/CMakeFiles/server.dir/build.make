# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/Acceptor.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/Acceptor.cpp.o: Acceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/Acceptor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/Acceptor.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Acceptor.cpp

CMakeFiles/server.dir/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/Acceptor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Acceptor.cpp > CMakeFiles/server.dir/Acceptor.cpp.i

CMakeFiles/server.dir/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/Acceptor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Acceptor.cpp -o CMakeFiles/server.dir/Acceptor.cpp.s

CMakeFiles/server.dir/Acceptor.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/Acceptor.cpp.o.requires

CMakeFiles/server.dir/Acceptor.cpp.o.provides: CMakeFiles/server.dir/Acceptor.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Acceptor.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/Acceptor.cpp.o.provides

CMakeFiles/server.dir/Acceptor.cpp.o.provides.build: CMakeFiles/server.dir/Acceptor.cpp.o


CMakeFiles/server.dir/Buffer.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/Buffer.cpp.o: Buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/Buffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/Buffer.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Buffer.cpp

CMakeFiles/server.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/Buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Buffer.cpp > CMakeFiles/server.dir/Buffer.cpp.i

CMakeFiles/server.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/Buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Buffer.cpp -o CMakeFiles/server.dir/Buffer.cpp.s

CMakeFiles/server.dir/Buffer.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/Buffer.cpp.o.requires

CMakeFiles/server.dir/Buffer.cpp.o.provides: CMakeFiles/server.dir/Buffer.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Buffer.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/Buffer.cpp.o.provides

CMakeFiles/server.dir/Buffer.cpp.o.provides.build: CMakeFiles/server.dir/Buffer.cpp.o


CMakeFiles/server.dir/Channel.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/Channel.cpp.o: Channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server.dir/Channel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/Channel.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Channel.cpp

CMakeFiles/server.dir/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/Channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Channel.cpp > CMakeFiles/server.dir/Channel.cpp.i

CMakeFiles/server.dir/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/Channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Channel.cpp -o CMakeFiles/server.dir/Channel.cpp.s

CMakeFiles/server.dir/Channel.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/Channel.cpp.o.requires

CMakeFiles/server.dir/Channel.cpp.o.provides: CMakeFiles/server.dir/Channel.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Channel.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/Channel.cpp.o.provides

CMakeFiles/server.dir/Channel.cpp.o.provides.build: CMakeFiles/server.dir/Channel.cpp.o


CMakeFiles/server.dir/EchoServer.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/EchoServer.cpp.o: EchoServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server.dir/EchoServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/EchoServer.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/EchoServer.cpp

CMakeFiles/server.dir/EchoServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/EchoServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/EchoServer.cpp > CMakeFiles/server.dir/EchoServer.cpp.i

CMakeFiles/server.dir/EchoServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/EchoServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/EchoServer.cpp -o CMakeFiles/server.dir/EchoServer.cpp.s

CMakeFiles/server.dir/EchoServer.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/EchoServer.cpp.o.requires

CMakeFiles/server.dir/EchoServer.cpp.o.provides: CMakeFiles/server.dir/EchoServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/EchoServer.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/EchoServer.cpp.o.provides

CMakeFiles/server.dir/EchoServer.cpp.o.provides.build: CMakeFiles/server.dir/EchoServer.cpp.o


CMakeFiles/server.dir/Epoll.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/Epoll.cpp.o: Epoll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server.dir/Epoll.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/Epoll.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Epoll.cpp

CMakeFiles/server.dir/Epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/Epoll.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Epoll.cpp > CMakeFiles/server.dir/Epoll.cpp.i

CMakeFiles/server.dir/Epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/Epoll.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Epoll.cpp -o CMakeFiles/server.dir/Epoll.cpp.s

CMakeFiles/server.dir/Epoll.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/Epoll.cpp.o.requires

CMakeFiles/server.dir/Epoll.cpp.o.provides: CMakeFiles/server.dir/Epoll.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Epoll.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/Epoll.cpp.o.provides

CMakeFiles/server.dir/Epoll.cpp.o.provides.build: CMakeFiles/server.dir/Epoll.cpp.o


CMakeFiles/server.dir/EventLoop.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/EventLoop.cpp.o: EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server.dir/EventLoop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/EventLoop.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/EventLoop.cpp

CMakeFiles/server.dir/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/EventLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/EventLoop.cpp > CMakeFiles/server.dir/EventLoop.cpp.i

CMakeFiles/server.dir/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/EventLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/EventLoop.cpp -o CMakeFiles/server.dir/EventLoop.cpp.s

CMakeFiles/server.dir/EventLoop.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/EventLoop.cpp.o.requires

CMakeFiles/server.dir/EventLoop.cpp.o.provides: CMakeFiles/server.dir/EventLoop.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/EventLoop.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/EventLoop.cpp.o.provides

CMakeFiles/server.dir/EventLoop.cpp.o.provides.build: CMakeFiles/server.dir/EventLoop.cpp.o


CMakeFiles/server.dir/TcpConnection.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/TcpConnection.cpp.o: TcpConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/server.dir/TcpConnection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/TcpConnection.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/TcpConnection.cpp

CMakeFiles/server.dir/TcpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/TcpConnection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/TcpConnection.cpp > CMakeFiles/server.dir/TcpConnection.cpp.i

CMakeFiles/server.dir/TcpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/TcpConnection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/TcpConnection.cpp -o CMakeFiles/server.dir/TcpConnection.cpp.s

CMakeFiles/server.dir/TcpConnection.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/TcpConnection.cpp.o.requires

CMakeFiles/server.dir/TcpConnection.cpp.o.provides: CMakeFiles/server.dir/TcpConnection.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/TcpConnection.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/TcpConnection.cpp.o.provides

CMakeFiles/server.dir/TcpConnection.cpp.o.provides.build: CMakeFiles/server.dir/TcpConnection.cpp.o


CMakeFiles/server.dir/TcpServer.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/TcpServer.cpp.o: TcpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/server.dir/TcpServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/TcpServer.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/TcpServer.cpp

CMakeFiles/server.dir/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/TcpServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/TcpServer.cpp > CMakeFiles/server.dir/TcpServer.cpp.i

CMakeFiles/server.dir/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/TcpServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/TcpServer.cpp -o CMakeFiles/server.dir/TcpServer.cpp.s

CMakeFiles/server.dir/TcpServer.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/TcpServer.cpp.o.requires

CMakeFiles/server.dir/TcpServer.cpp.o.provides: CMakeFiles/server.dir/TcpServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/TcpServer.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/TcpServer.cpp.o.provides

CMakeFiles/server.dir/TcpServer.cpp.o.provides.build: CMakeFiles/server.dir/TcpServer.cpp.o


CMakeFiles/server.dir/TimerQueue.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/TimerQueue.cpp.o: TimerQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/server.dir/TimerQueue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/TimerQueue.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/TimerQueue.cpp

CMakeFiles/server.dir/TimerQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/TimerQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/TimerQueue.cpp > CMakeFiles/server.dir/TimerQueue.cpp.i

CMakeFiles/server.dir/TimerQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/TimerQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/TimerQueue.cpp -o CMakeFiles/server.dir/TimerQueue.cpp.s

CMakeFiles/server.dir/TimerQueue.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/TimerQueue.cpp.o.requires

CMakeFiles/server.dir/TimerQueue.cpp.o.provides: CMakeFiles/server.dir/TimerQueue.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/TimerQueue.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/TimerQueue.cpp.o.provides

CMakeFiles/server.dir/TimerQueue.cpp.o.provides.build: CMakeFiles/server.dir/TimerQueue.cpp.o


CMakeFiles/server.dir/Timestamp.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/Timestamp.cpp.o: Timestamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/server.dir/Timestamp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/Timestamp.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Timestamp.cpp

CMakeFiles/server.dir/Timestamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/Timestamp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Timestamp.cpp > CMakeFiles/server.dir/Timestamp.cpp.i

CMakeFiles/server.dir/Timestamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/Timestamp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/Timestamp.cpp -o CMakeFiles/server.dir/Timestamp.cpp.s

CMakeFiles/server.dir/Timestamp.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/Timestamp.cpp.o.requires

CMakeFiles/server.dir/Timestamp.cpp.o.provides: CMakeFiles/server.dir/Timestamp.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Timestamp.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/Timestamp.cpp.o.provides

CMakeFiles/server.dir/Timestamp.cpp.o.provides.build: CMakeFiles/server.dir/Timestamp.cpp.o


CMakeFiles/server.dir/main.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/server.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/main.cpp.o -c /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/main.cpp

CMakeFiles/server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/main.cpp > CMakeFiles/server.dir/main.cpp.i

CMakeFiles/server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/main.cpp -o CMakeFiles/server.dir/main.cpp.s

CMakeFiles/server.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/main.cpp.o.requires

CMakeFiles/server.dir/main.cpp.o.provides: CMakeFiles/server.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/main.cpp.o.provides

CMakeFiles/server.dir/main.cpp.o.provides.build: CMakeFiles/server.dir/main.cpp.o


# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/Acceptor.cpp.o" \
"CMakeFiles/server.dir/Buffer.cpp.o" \
"CMakeFiles/server.dir/Channel.cpp.o" \
"CMakeFiles/server.dir/EchoServer.cpp.o" \
"CMakeFiles/server.dir/Epoll.cpp.o" \
"CMakeFiles/server.dir/EventLoop.cpp.o" \
"CMakeFiles/server.dir/TcpConnection.cpp.o" \
"CMakeFiles/server.dir/TcpServer.cpp.o" \
"CMakeFiles/server.dir/TimerQueue.cpp.o" \
"CMakeFiles/server.dir/Timestamp.cpp.o" \
"CMakeFiles/server.dir/main.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/Acceptor.cpp.o
server: CMakeFiles/server.dir/Buffer.cpp.o
server: CMakeFiles/server.dir/Channel.cpp.o
server: CMakeFiles/server.dir/EchoServer.cpp.o
server: CMakeFiles/server.dir/Epoll.cpp.o
server: CMakeFiles/server.dir/EventLoop.cpp.o
server: CMakeFiles/server.dir/TcpConnection.cpp.o
server: CMakeFiles/server.dir/TcpServer.cpp.o
server: CMakeFiles/server.dir/TimerQueue.cpp.o
server: CMakeFiles/server.dir/Timestamp.cpp.o
server: CMakeFiles/server.dir/main.cpp.o
server: CMakeFiles/server.dir/build.make
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/requires: CMakeFiles/server.dir/Acceptor.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/Buffer.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/Channel.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/EchoServer.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/Epoll.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/EventLoop.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/TcpConnection.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/TcpServer.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/TimerQueue.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/Timestamp.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/main.cpp.o.requires

.PHONY : CMakeFiles/server.dir/requires

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8 /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8 /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8 /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8 /mnt/hgfs/Ubuntu/Myserver/mini-server-v1.8/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

