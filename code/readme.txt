编译
    编译依赖于maven，版本3.5.0，确保maven安装目录下bin子目录在path环境变量中。
	步骤：
	1，执行lib/install2mvn.bat命令，用于上传本项目依赖的第三方jar包到本地maven仓库中
	2，命令行中执行
	    mvn clean install
	3,cd ei-console
	4,mvn spring-boot:run
	   或者java -jar ei-console-1.0.jar