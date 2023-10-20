# 管理子系统
touch manager_view.h manager_view_impl.h manager_view_impl.cpp 
touch manager_ctrl.h manager_ctrl_impl.h manager_ctrl_impl.cpp 
touch manager_mode.h manager_mode_impl.h manager_mode_impl.cpp
touch manager.h manager.cpp
# 业务子系统
touch service_view.h service_view_impl.h service_view_impl.cpp
touch service_ctrl.h service_ctrl_impl.h service_ctrl_impl.cpp
touch service_mode.h service_mode_impl.h service_mode_impl.cpp
touch department.h department.cpp
touch employee.h employee.cpp
# 基础设施及辅助工具
touch emis.h emis.cpp
touch tools.h tools.cpp
touch main.cpp

# 编译脚本
ls *.cpp > Makefile
ls * > emis.conf
