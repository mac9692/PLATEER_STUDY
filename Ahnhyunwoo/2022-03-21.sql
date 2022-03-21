-- 코드를 입력하세요
select name, datetime
from (SELECT name, datetime
from animal_ins
where animal_id not in (select b.animal_id from animal_outs b )
order by datetime)
where rownum <= 3
     
