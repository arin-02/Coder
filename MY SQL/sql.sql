create database arin;
show databases;
use arin;

create table worker (
worker_id int not null primary key auto_increment,
first_name varchar(25),
last_name varchar(25),
salary int(55),
joining_date datetime,
department varchar(25)
);

insert into worker(worker_id,first_name,last_name,salary,
joining_date,department) values
	(001,'Cashmere','Arora',100000,'2022-07-01 09:00:00','Clerk'),
    (002,'Karan','Gupta',200000,'2022-05-03 08:00:00','Manager'),
    (003,'Priyanshu','Narwaria',150000,'2022-02-09 05:00:00','MALIK');
    
    select * from worker;
    
create table bonus (
worker_ref_id int,
bonus_amount int(10),
bonus_date date,
foreign key (worker_ref_id)
references worker(worker_id)
on delete cascade
);
insert into bonus
			(worker_ref_id,bonus_amount,bonus_date) values
            (001,1323324,'2020-05-02'),
            (002,1234235,'2021-02-07'),
            (001,3456346,'2022-01-04'),
            (003,2312312,'2022-04-04');
select * from bonus;
