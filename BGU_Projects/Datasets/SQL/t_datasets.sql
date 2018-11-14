USE DATASETS;

DROP TABLE IF EXISTS T_DATASETS;

CREATE TABLE T_DATASETS
(
	DATASET_ID		INTEGER	NOT NULL PRIMARY KEY,
	DATASET_NAME	VARCHAR (50),
	URL				VARCHAR (200),
	STRUCTURE		VARCHAR (200),
	DESCRIPTION		VARCHAR (200),
	USERNAME		VARCHAR (200),
	PASSWD			VARCHAR (50)
)