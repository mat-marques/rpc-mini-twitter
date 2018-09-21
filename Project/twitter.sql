

CREATE DATABASE twitter;


CREATE TABLE user(
    id VARCHAR(50)
);

ALTER TABLE user ADD CONSTRAINT  pk_user_id PRIMARY KEY(id);

CREATE TABLE topic(
    topic VARCHAR(50)
);

ALTER TABLE topic ADD CONSTRAINT pk_topic PRIMARY KEY(topic);


CREATE TABLE twitte(
    id int AUTO_INCREMENT,
    id_user VARCHAR(50),
    text VARCHAR(80),
    twitte_time timestamp,
    topic VARCHAR(50)
);

ALTER TABLE twitte ADD CONSTRAINT pk_twitte PRIMARY KEY(id);
ALTER TABLE twitte ADD CONSTRAINT fk_twitte_id_user FOREING KEY(id_user) REFERENCES user(id);
ALTER TABLE twitte ADD CONSTRAINT fk_twitte_topic FOREING KEY(topic) REFERENCES topic(topic);

CREATE TABLE followers(
    id_user VARCHAR(50),
    id_follower VARCHAR(50)
);

ALTER TABLE followers ADD CONSTRAINT fk_followers_id_user FOREING KEY(id_user) REFERENCES user(id);
ALTER TABLE followers ADD CONSTRAINT fk_followers_id_follower FOREING KEY(id_follower) REFERENCES user(id);
ALTER TABLE follower ADD CONSTRAINT pk_followers PRIMARY KEY(id_user, id_follower);

