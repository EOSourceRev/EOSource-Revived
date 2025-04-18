
CREATE TABLE IF NOT EXISTS `accounts`
(
	`username`   VARCHAR(16) NOT NULL,
	`password`   CHAR(64)    NOT NULL,
	`fullname`   VARCHAR(64) NOT NULL,
	`location`   VARCHAR(64) NOT NULL,
	`email`      VARCHAR(64) NOT NULL,
	`computer`   VARCHAR(64) NOT NULL,
	`hdid`       INTEGER     NOT NULL,
	`regip`      VARCHAR(15) NOT NULL,
	`lastip`     VARCHAR(15)          DEFAULT NULL,
	`created`    INTEGER     NOT NULL,
	`lastused`   INTEGER              DEFAULT NULL,

	PRIMARY KEY (`username`)
);

CREATE TABLE IF NOT EXISTS `characters`
(
	`name`           VARCHAR(16) NOT NULL,
	`account`        VARCHAR(16)          DEFAULT NULL,
	`title`          VARCHAR(32)          DEFAULT NULL,
	`home`           VARCHAR(32)          DEFAULT NULL,
	`fiance`         VARCHAR(16)          DEFAULT NULL,
	`partner`        VARCHAR(16)          DEFAULT NULL,
	`admin`          INTEGER     NOT NULL DEFAULT 0,
	`class`          INTEGER     NOT NULL DEFAULT 1,
	`gender`         INTEGER     NOT NULL DEFAULT 0,
	`race`           INTEGER     NOT NULL DEFAULT 0,
	`hairstyle`      INTEGER     NOT NULL DEFAULT 0,
	`haircolor`      INTEGER     NOT NULL DEFAULT 0,
	`map`            INTEGER     NOT NULL DEFAULT 192,
	`x`              INTEGER     NOT NULL DEFAULT 7,
	`y`              INTEGER     NOT NULL DEFAULT 6,
	`direction`      INTEGER     NOT NULL DEFAULT 2,
	`level`          INTEGER     NOT NULL DEFAULT 0,
	`exp`            INTEGER     NOT NULL DEFAULT 0,
	`hp`             INTEGER     NOT NULL DEFAULT 10,
	`tp`             INTEGER     NOT NULL DEFAULT 10,
	`str`            INTEGER     NOT NULL DEFAULT 0,
	`int`            INTEGER     NOT NULL DEFAULT 0,
	`wis`            INTEGER     NOT NULL DEFAULT 0,
	`agi`            INTEGER     NOT NULL DEFAULT 0,
	`con`            INTEGER     NOT NULL DEFAULT 0,
	`cha`            INTEGER     NOT NULL DEFAULT 0,
	`statpoints`     INTEGER     NOT NULL DEFAULT 0,
	`skillpoints`    INTEGER     NOT NULL DEFAULT 0,
	`karma`          INTEGER     NOT NULL DEFAULT 1000,
	`sitting`        INTEGER     NOT NULL DEFAULT 0,
	`nointeract`     INTEGER     NOT NULL DEFAULT 0,
	`bankmax`        INTEGER     NOT NULL DEFAULT 0,
	`goldbank`       INTEGER     NOT NULL DEFAULT 0,
	`usage`          INTEGER     NOT NULL DEFAULT 0,
	`inventory`      TEXT,
	`bank`           TEXT,
	`paperdoll`      TEXT,
	`spells`         TEXT,
	`guild`          CHAR(3)              DEFAULT NULL,
	`guild_rank`     INTEGER              DEFAULT NULL,
	`quest`          TEXT,
	`vars`           TEXT,
	`achievements`   TEXT                 DEFAULT NULL,
	`oldmap`         INTEGER     	   DEFAULT 0,
	`oldx`           INTEGER     	   DEFAULT 0,
	`oldy`           INTEGER     	   DEFAULT 0,
	`flevel`         INTEGER     NOT NULL DEFAULT 0,
	`fexp`           INTEGER     NOT NULL DEFAULT 0,
	`mlevel`         INTEGER     NOT NULL DEFAULT 0,
	`mexp`           INTEGER     NOT NULL DEFAULT 0,
	`wlevel`         INTEGER     NOT NULL DEFAULT 0,
	`wexp`           INTEGER     NOT NULL DEFAULT 0,
	`clevel`         INTEGER     NOT NULL DEFAULT 0,
	`cexp`           INTEGER     NOT NULL DEFAULT 0,
	`immune`         INTEGER     NOT NULL DEFAULT 0,
	`rebirth`        INTEGER     	   DEFAULT 0,
	`member`         INTEGER     	   DEFAULT 0,
	`bounty`         INTEGER     	   DEFAULT 0,
	`guild_rankname` TEXT              DEFAULT NULL,
	`warn`           INTEGER     NOT NULL DEFAULT 0,
	`lockerpin`      INTEGER     	   DEFAULT 0,
	`oldhairstyle`   INTEGER     NOT NULL DEFAULT 0,

	PRIMARY KEY (`name`)
);

CREATE TABLE IF NOT EXISTS `pets`
(
        `name`        VARCHAR(16)          DEFAULT NULL,
        `owner_name`  VARCHAR(16)          DEFAULT NULL,
        `npcid`       INTEGER     NOT NULL DEFAULT 0,
        `rebirth`     INTEGER     NOT NULL DEFAULT 0,
        `level`       INTEGER     NOT NULL DEFAULT 0,
        `exp`         INTEGER     NOT NULL DEFAULT 0,
        `hp`          INTEGER     NOT NULL DEFAULT 0,
        `tp`          INTEGER     NOT NULL DEFAULT 0,
        `petinvmax`   INTEGER     NOT NULL DEFAULT 0,
        `inventory`   TEXT
);

CREATE TABLE IF NOT EXISTS `guilds`
(
	`tag`         CHAR(3)     NOT NULL,
	`name`        VARCHAR(32) NOT NULL,
	`description` TEXT,
	`created`     INTEGER     NOT NULL,
	`ranks`       TEXT,
	`bank`        INTEGER     NOT NULL DEFAULT 0,

	PRIMARY KEY (`tag`),
	UNIQUE      (`name`)
);

CREATE TABLE IF NOT EXISTS `bans`
(
	`ip`       INTEGER              DEFAULT NULL,
	`hdid`     INTEGER              DEFAULT NULL,
	`username` VARCHAR(16)          DEFAULT NULL,
	`setter`   VARCHAR(16)          DEFAULT NULL,
	`expires`  INTEGER     NOT NULL DEFAULT 0,

	PRIMARY KEY (`ip`, `hdid`, `username`, `expires`)
);

CREATE TABLE IF NOT EXISTS `reports`
(
	`reporter` VARCHAR(16) NOT NULL,
	`reported` VARCHAR(16) NOT NULL,
	`reason`   TEXT,
	`time`     INTEGER     NOT NULL,
	`chat_log` TEXT        NOT NULL,
	
	PRIMARY KEY (`reporter`, `reported`, `time`)
);

CREATE INDEX `character_account_index` ON `characters` (`account`);
CREATE INDEX `character_guild_index` ON `characters` (`guild`);
CREATE INDEX `ban_ip_index` ON `bans` (`ip`);
CREATE INDEX `ban_hdid_index` ON `bans` (`hdid`);
CREATE INDEX `ban_username_index` ON `bans` (`username`);
