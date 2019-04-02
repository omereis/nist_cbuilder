BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "SAMPLES" (
	"SAMPLE_ID"	INTEGER,
	"VALUE"	NUMERIC,
	"SOURCE_ID"	INTEGER,
	"IS_VALID"	INTEGER,
	PRIMARY KEY("SAMPLE_ID"),
	FOREIGN KEY("SOURCE_ID") REFERENCES "TEMPS_SOURCE"("SOURCE_ID") on update cascade on delete cascade
);
CREATE TABLE IF NOT EXISTS "SAMPLE_COMMENTS" (
	"COMMENT_ID"	INTEGER,
	"SAMPLE_ID"	INTEGER,
	"COMMENTS"	TEXT,
	PRIMARY KEY("COMMENT_ID"),
	FOREIGN KEY("SAMPLE_ID") REFERENCES "SAMPLES"("SAMPLE_ID") on update cascade on delete cascade
);
CREATE TABLE IF NOT EXISTS "TEMPS_SOURCE" (
	"SOURCE_ID"	INTEGER,
	"DESC"	TEXT,
	PRIMARY KEY("SOURCE_ID")
);
COMMIT;
