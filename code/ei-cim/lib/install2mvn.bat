call mvn install:install-file -DgroupId=com.znd -DartifactId=ZhongNDMemDB -Dversion=1.0 -Dpackaging=jar -Dfile=ZhongNDMemDB.jar
call mvn install:install-file -DgroupId=com.znd -DartifactId=ZhongNDRedisDF -Dversion=1.0 -Dpackaging=jar -Dfile=ZhongNDRedisDF.jar
call mvn install:install-file -DgroupId=com.znd -DartifactId=ZhongNDRedisADF -Dversion=1.0 -Dpackaging=jar -Dfile=ZhongNDRedisADF.jar
call mvn install:install-file -DgroupId=redis.clients -DartifactId=jedis -Dversion=3.0.0 -Dpackaging=jar -Dfile=jedis-3.0.0.jar