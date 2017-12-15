call mvn install:install-file -DgroupId=com.znd -DartifactId=ZhongNDMemDB -Dversion=3.2 -Dpackaging=jar -Dfile=ZhongNDMemDB.jar
call mvn install:install-file -DgroupId=com.znd -DartifactId=ZhongNDRedisDF -Dversion=3.2 -Dpackaging=jar -Dfile=ZhongNDRedisDF-V3.0.jar
call mvn install:install-file -DgroupId=com.znd -DartifactId=ZhongNDRedisADF -Dversion=3.2 -Dpackaging=jar -Dfile=ZhongNDRedisADF-V2.0.jar
@rem call mvn install:install-file -DgroupId=redis.clients -DartifactId=jedis -Dversion=3.0.0 -Dpackaging=jar -Dfile=jedis-3.0.0.jar
pause