CC=g++
STD=-std=c++11
FLAG=-Wall -Werror
TARGET=HMS
USER_FILES=user_files/msg.txt

#头文件路径
INCDIRS:=tools \
		 guest \
		 room \
		 hotel

#源文件路径
SRCDIRS:=project \
		 hotel \
		 tools \

#使用patsubst函数将INCDIRS中的每个内容加上-I
#编译时作为参数(头文件路径)
INCLUDE:=$(patsubst %, -I %, $(INCDIRS))				   

#获取对应目录的源文件.cpp
CPPFILES:=$(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))

#将CPPFILES中的内容去掉目录名,即获取对应源文件
CPPFILENDIR:=$(notdir $(CPPFILES))

#获取源文件对应的.o文件,加上obj目录
OBJS:=$(patsubst %, obj/%, $(CPPFILENDIR:.cpp=.o))

#添加目标及依赖搜索路径
VPATH:=$(SRCDIRS)


#print:
#	@echo INCDIRS = $(INCDIRS)
#	@echo INCLUDE = $(INCLUDE)
#	@echo CPPFILES = $(CPPFILES)
#	@echo CPPFILENDIR = $(CPPFILENDIR)
#	@echo OBJS = $(OBJS)

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ && ./$(TARGET) $(USER_FILES)

$(OBJS):obj/%.o:%.cpp
	$(CC) $(FLAG) $(STD) -c $(INCLUDE) $< -o $@ 


.PHONY:clean
clean:
	rm -rf $(OBJS) $(TARGET)
	rm -rf *~ *.h.gch
