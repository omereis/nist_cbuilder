/*
SQLyog Community v9.20 
MySQL - 5.5.15 
*********************************************************************
*/
/*!40101 SET NAMES utf8 */;

create table `t_points` (
	`POINT_ID` int (11),
	`DATASET_ID` int (11),
	`OBJECT_ID` int (11),
	`LNG` double ,
	`LAT` double ,
	`ALT` double ,
	`PT_TIME` datetime 
); 
