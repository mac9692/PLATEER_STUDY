SELECT ANIMAL_ID, NAME, TO_CHAR(DATETIME, 'YYYY-MM-DD') as "날짜"
From ANIMAL_INS
order by ANIMAL_ID