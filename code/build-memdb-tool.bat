cd src/ei-memdb-core
call mvn clean install -Dmaven.test.skip=true
cd ../..
cd src/ei-memdb-tool
call mvn clean install -Dmaven.test.skip=true
cd ../..