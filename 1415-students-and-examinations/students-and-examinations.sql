SELECT s.student_id, s.student_name, sub.subject_name,
       IFNULL((SELECT COUNT(*) 
               FROM Examinations AS e 
               WHERE e.student_id = s.student_id AND e.subject_name = sub.subject_name), 0) AS attended_exams
FROM Students AS s
CROSS JOIN Subjects AS sub
ORDER BY s.student_id, sub.subject_name;
