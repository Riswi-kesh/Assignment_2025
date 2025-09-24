CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    name VARCHAR(50),
    age INT,
    grade CHAR(1),
    marks INT
);

INSERT INTO Students VALUES (1, 'Amit', 20, 'A', 85);
INSERT INTO Students VALUES (2, 'Riya', 21, 'B', 72);
INSERT INTO Students VALUES (3, 'Kiran', 19, 'A', 90);
INSERT INTO Students VALUES (4, 'Sneha', 22, 'C', 60);
INSERT INTO Students VALUES (5, 'Raj', 20, 'B', 75);

-- 1. Find the average marks of all students
SELECT AVG(marks) AS average_marks FROM Students;

-- 2. Find the highest marks
SELECT MAX(marks) AS highest_marks FROM Students;

-- 3. Find the lowest marks
SELECT MIN(marks) AS lowest_marks FROM Students;

-- 4. Count total number of students
SELECT COUNT(*) AS total_students FROM Students;

-- 5. Find average marks grade-wise
SELECT grade, AVG(marks) AS avg_marks
FROM Students
GROUP BY grade;
