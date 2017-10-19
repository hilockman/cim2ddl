cd src/ei-ads-core
call mvn clean install -Dmaven.test.skip=true
cd ../..
cd src/ei-acp-dfredisson
call mvn clean install -Dmaven.test.skip=true
cd ../..
cd src/ei-apl-reliability
call mvn clean install -Dmaven.test.skip=true
cd ../..
cd src/ei-ads-console
call mvn clean install -Dmaven.test.skip=true
cd ../..