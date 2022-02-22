#include <hiredis/hiredis.h>
#include <stdio.h>

/*
 * Use redis to maintain list of failed tls FQDN
 */
#define FAILED_FQDN "failedFQDN"
#define REDIS_SERVER "127.0.0.1"
#define REDIS_PORT 6379

static const char *redis_server = REDIS_SERVER;
static const int redis_port = REDIS_PORT;

int failedDN_on_list(char *s) {
	int rc = 0;
	redisContext *c = redisConnect(redis_server, redis_port);
	if (!c) return 0;
	if (c->err) return 0;
	redisReply *reply;
	reply = redisCommand(c, "SISMEMBER %s %s", FAILED_FQDN, s);
	if (reply->type == REDIS_REPLY_INTEGER) {
		rc = reply->integer;
	}
	freeReplyObject(reply);
	redisFree(c);
	return rc;
}

int failedDN_add(char *s) {
	int rc = 0;
	redisContext *c = redisConnect(redis_server, redis_port);
	if (!c) return 0;
	if (c->err) return 0;
	redisReply *reply;
	reply = redisCommand(c, "SADD %s %s", FAILED_FQDN, s);
	if (reply->type == REDIS_REPLY_INTEGER) {
		rc = reply->integer;
	}
	freeReplyObject(reply);
	redisFree(c);
	return rc;
}

int failedDN_del(char *s) {
	int rc = 0;
	redisContext *c = redisConnect(redis_server, redis_port);
	if (!c) return 0;
	if (c->err) return 0;
	redisReply *reply;
	reply = redisCommand(c, "SREM %s %s", FAILED_FQDN, s);
	if (reply->type == REDIS_REPLY_INTEGER) {
		rc = reply->integer;
	}
	freeReplyObject(reply);
	redisFree(c);
	return rc;
}

int failedDN_get_all(void (*fn)(char *)) {
	int rc = 0;
	redisContext *c = redisConnect(redis_server, redis_port);
	if (!c) return 0;
	if (c->err) return 0;
	redisReply *reply;
	reply = redisCommand(c, "SMEMBERS %s", FAILED_FQDN);
	if (reply->type == REDIS_REPLY_ARRAY) {
		rc = reply->elements;
		for (int i=0; i<reply->elements; i++) {
			if (fn) fn(reply->element[i]->str);
		}
	}
	freeReplyObject(reply);
	redisFree(c);
	return rc;
}

int failedDN_get_keys(void(*fn)()) {
	int rc = 0;
	redisContext *c = redisConnect(redis_server, redis_port);
	if (!c) return 0;
	if (c->err) return 0;
	redisReply *reply;
	reply = redisCommand(c, "KEYS *");
	if (reply->type == REDIS_REPLY_ARRAY) {
		rc = reply->elements;
		for (int i=0; i<reply->elements; i++) {
			if (fn) fn(reply->element[i]->str);
		}
	}
	freeReplyObject(reply);
	redisFree(c);
	return rc;
}
