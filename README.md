# Locker
A practice for TDD
***   
### Tasking - Locker
**Given** 小型locker容量为10,一个小型包  **When** locker 存包  **Then** 存包成功，返回票据  

**Given** 小型locker存了一个小型包，一张正确的票  **When** locker 取包  **Then** 取包成功，返回正确的包 

**Given** 小型locker存满了包，一个小型包  **When** locker 存包  **Then** 返回容量已满 

**Given** 小型locker正确存入一个小型包，一张伪造的票 **When** locker 取包  **Then** 返回票无效错误

**Given** 小型locker正确存入一个小型包，一张中型包的票 **When** locker 取包  **Then** 返回票类型不匹配
***  
### Tasking - PrimaryLockerRobot
**Given** PrimaryLockerRobot保管两个非空中型locker，一个中型包  **When** PrimaryLockerRobot 存包  **Then** 存包成功，返回票据，包在第一个locker中

**Given** PrimaryLockerRobot保管两个中型locker，第一个locker满，有个中型包  **When** PrimaryLockerRobot 存包  **Then** 存包成功，返回票据，包在第二个locker中

**Given** PrimaryLockerRobot正确存入一个中型包，一张正确的票  **When** PrimaryLockerRobot 取包  **Then** 取包成功，返回正确的包 

**Given** PrimaryLockerRobot正确存入一个中型包，一张伪造的票 **When** PrimaryLockerRobot 取包  **Then** 返回票无效错误

**Given** PrimaryLockerRobot正确存入一个中型包，一张小型包的票 **When** PrimaryLockerRobot 取包  **Then** 返回票类型不匹配

**Given** PrimaryLockerRobot保管1个小型locker，一个包  **When** PrimaryLockerRobot 存包  **Then** 存包失败，返回机器人故障
***  
### Tasking - SuperLockerRobot
**Given** SuperLockerRobot保管两个大型locker，有个大型包  **When** SuperLockerRobot 存包  **Then** 存包成功，返回票据

**Given** SuperLockerRobot保管两个中型locker，第一个locker剩余2，第二个locker剩余3，有个大型包  **When** SuperLockerRobot 存包  **Then** 存包成功，返回票据，包在第二个locker中

**Given** SuperLockerRobot正确存入一个大型包，一张正确的票  **When** SuperLockerRobot 取包  **Then** 取包成功，返回正确的包 

**Given** SuperLockerRobot正确存入一个大型包，一张伪造的票 **When** SuperLockerRobot 取包  **Then** 返回票无效错误

**Given** SuperLockerRobot正确存入一个大型包，一张小型包的票 **When** SuperLockerRobot 取包  **Then** 返回票类型不匹配

**Given** SuperLockerRobot保管1个小型locker，一个大型包  **When** SuperLockerRobot 存包  **Then** 存包失败，返回机器人故障
***  
### Tasking - LockerRobotManager
**Given** SuperLockerRobot保管1个大型locker，PrimaryLockerRobot保管1个中型locker, 一个LockerRobotManager管理前面描述的两个robot和一个小型locker， 
一个小型包 **When** LockerRobotManager存小型包  **Then** 存包成功，返回票据， 小型包存入小型locker中

**Given** SuperLockerRobot保管1个大型locker，PrimaryLockerRobot保管1个中型locker, 一个LockerRobotManager管理前面描述的两个robot和一个小型locker， 
一个中型包 **When** LockerRobotManager存中型包  **Then** 存包成功，返回票据， 中型包存入中型locker中

**Given** SuperLockerRobot保管1个大型locker，PrimaryLockerRobot保管1个中型locker, 一个LockerRobotManager管理前面描述的两个robot和一个小型locker， 
一个大型包 **When** LockerRobotManager存大型包  **Then** 存包成功，返回票据， 中型包存入大型locker中

**Given** SuperLockerRobot保管1个大型locker，PrimaryLockerRobot保管1个中型locker, 一个LockerRobotManager管理前面描述的两个robot和一个小型locker， 
LockerRobotManager已存入一个小型包，一张票正确的票 **When** LockerRobotManager取包 **Then** 取包成功，返回正确的包 

**Given** SuperLockerRobot保管1个大型locker，PrimaryLockerRobot保管1个中型locker, 一个LockerRobotManager管理前面描述的两个robot和一个小型locker， 
LockerRobotManager已存入一个中型包，一张票正确的票 **When** LockerRobotManager取包 **Then** 取包成功，返回正确的包 

**Given** SuperLockerRobot保管1个大型locker，PrimaryLockerRobot保管1个中型locker, 一个LockerRobotManager管理前面描述的两个robot和一个小型locker， 
LockerRobotManager已存入一个大型包，一张票正确的票 **When** LockerRobotManager取包 **Then** 取包成功，返回正确的包 

**Given** SuperLockerRobot保管1个大型locker，PrimaryLockerRobot保管1个中型locker, 一个LockerRobotManager管理前面描述的两个robot和一个小型locker， 
LockerRobotManager已存入一个包，一张伪造的票 **When** LockerRobotManager取包 **Then** 返回票无效错误

**Given** SuperLockerRobot保管1个大型locker，PrimaryLockerRobot保管1个中型locker, 一个LockerRobotManager管理前面描述的两个robot和一个小型locker， 
LockerRobotManager已存入一个大型包，一张小型包的票 **When** LockerRobotManager取包 **Then** 返回票类型不匹配

**Given** SuperLockerRobot保管1个中型locker，PrimaryLockerRobot保管1个小型locker, 一个LockerRobotManager管理前面描述的两个robot和一个小型locker， 
一个大型包 **When** LockerRobotManager存小型包  **Then** 存包失败，返回机器人故障
*** 
