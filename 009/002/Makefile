####################
# 函数
#  foreach
#  filter
#  filter-out
#  wildcard   取出其中存在的文件
#  patsubstr

######################
# gcc -M c.c # 打印依赖
# gcc -M -MF c.d c.c # 把依赖写入文件c.d
# gcc -c -o c.o c.c -MD -MF c.d # 编译 c.c, 生成 c.o, 把依赖写入 c.d
# CFLAGS 编译参数

objs = a.o b.o c.o

dep_files := $(patsubst %, .%.d, $(objs))
dep_files := $(wildcard $(dep_files))


CFLAGS = -Werror -Iinclude

all:$(objs)
	gcc -o test $^

# 不为空
ifneq ($(dep_files),)
include $(dep_files)
endif


%.o:%.c
	gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d

clean:
	rm *.o test 


distclean:
	rm $(dep_files)

# 定义假想目标, 如果目录下存在clean文件，则需要定义假想目标
.PHONY:	clean

