-- This does not work
-- select name
-- from customer
-- where referee_id = null or referee_id != 2;

select name 
from customer 
where referee_id is null or referee_id!=2;