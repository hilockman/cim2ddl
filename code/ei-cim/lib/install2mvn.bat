call mvn install:install-file -DgroupId=com.znd -DartifactId=ZhongNDMemDB -Dversion=2.0 -Dpackaging=jar -Dfile=ZhongNDMemDB.jar
call mvn install:install-file -DgroupId=com.znd -DartifactId=ZhongNDRedisDF -Dversion=2.0 -Dpackaging=jar -Dfile=ZhongNDRedisDF-V2.0.jar
call mvn install:install-file -DgroupId=com.znd -DartifactId=ZhongNDRedisADF -Dversion=2.0 -Dpackaging=jar -Dfile=ZhongNDRedisADF.jar
call mvn install:install-file -DgroupId=redis.clients -DartifactId=jedis -Dversion=3.0.0 -Dpackaging=jar -Dfile=jedis-3.0.0.jar