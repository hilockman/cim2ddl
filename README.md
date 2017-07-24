# cim2ddl
Create DDL automatically, and implement mapping of CIM to relational database.

1, What is DDL and DML
https://stackoverflow.com/questions/2578194/what-is-ddl-and-dml
Data Definition Language (DDL) statements are used to define the database structure or schema. Some examples:
 1. CREATE - to create objects in the database
 2. ALTER - alters the structure of the database 
 3. DROP - delete objects from the database
 4. TRUNCATE - remove all records from a table, including all spaces allocated for the records are removed
 5. COMMENT - add comments to the data dictionary
 6. RENAME - rename an object
 
 Data Manipulation Language (DML) statements are used for managing data within schema objects. Some examples:
 1. SELECT - retrieve data from the a database 
 2. INSERT - insert data into a table UPDATE - updates existing data within a table
 3. DELETE - deletes all records from a table, the space for the records remain
 4. MERGE - UPSERT operation (insert or update)
 5. CALL - call a PL/SQL or Java subprogram    
 6. EXPLAIN PLAN - explain access path to data 
 7. LOCK TABLE - control concurrency
