cd src/ei-base
call mvn clean install -Dmaven.test.skip=true
cd ../..
cd src/ei-ads-base
call mvn clean install -Dmaven.test.skip=true
cd ../..
cd src/ei-ads-buffer
call mvn clean install -Dmaven.test.skip=true
cd ../..
cd src/ei-ads-server
call mvn clean install -Dmaven.test.skip=true
cd ../..
cd src/ei-memdb
call mvn clean install -Dmaven.test.skip=true
cd ../..
cd src/ei-ads-node
call mvn clean install -Dmaven.test.skip=true
cd ../..