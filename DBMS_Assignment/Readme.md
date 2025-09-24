# DBMS Assignment - V3 Aggregation Queries

This assignment demonstrates **Aggregation Queries** in SQL.

## Table Used
**Students**
- student_id (INT, Primary Key)
- name (VARCHAR)
- age (INT)
- grade (CHAR)
- marks (INT)

## Queries Implemented
1. Average marks of all students  
   ```sql
   SELECT AVG(marks) FROM Students;
