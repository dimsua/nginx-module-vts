
/*
 * Copyright (C) YoungJoo Kim (vozlt)
 */


#ifndef _NGX_HTTP_VTS_MODULE_H_INCLUDED_
#define _NGX_HTTP_VTS_MODULE_H_INCLUDED_


#include <nginx.h>
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

#include "ngx_http_vhost_traffic_status_string.h"
#include "ngx_http_vhost_traffic_status_node.h"

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_NO          0
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_UA          1
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_UG          2
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_CC          3
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_FG          4

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAMS            (u_char *) "NO\0UA\0UG\0CC\0FG\0"

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_NODE_NONE            0
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_NODE_FIND            1

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_KEY_SEPARATOR        (u_char) 0x1f

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_FORMAT_NONE          0
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_FORMAT_JSON          1
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_FORMAT_HTML          2
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_FORMAT_JSONP         3

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_AVERAGE_METHOD_AMM   0
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_AVERAGE_METHOD_WMA   1

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_DEFAULT_SHM_NAME     "ngx_http_vhost_traffic_status"
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_DEFAULT_SHM_SIZE     0xfffff
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_DEFAULT_JSONP        "ngx_http_vhost_traffic_status_jsonp_callback"
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_DEFAULT_SUM_KEY      "*"
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_DEFAULT_AVG_PERIOD   60
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_DEFAULT_DUMP_PERIOD  60

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_S           "{"
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_OBJECT_S    "\"%V\":{"
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_ARRAY_S     "\"%V\":["

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_ARRAY_E     "]"
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_OBJECT_E    "}"
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_E           "}"
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_NEXT        ","

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_MAIN "\"hostName\":\"%V\","     \
    "\"nginxVersion\":\"%s\","                                                 \
    "\"loadMsec\":%M,"                                                         \
    "\"nowMsec\":%M,"                                                          \
    "\"connections\":{"                                                        \
    "\"active\":%uA,"                                                          \
    "\"reading\":%uA,"                                                         \
    "\"writing\":%uA,"                                                         \
    "\"waiting\":%uA,"                                                         \
    "\"accepted\":%uA,"                                                        \
    "\"handled\":%uA,"                                                         \
    "\"requests\":%uA"                                                         \
    "},"                                                                       \
    "\"sharedZones\":{"                                                        \
    "\"name\":\"%V\","                                                         \
    "\"maxSize\":%ui,"                                                         \
    "\"usedSize\":%ui,"                                                        \
    "\"usedNode\":%ui"                                                         \
    "},"

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_SERVER_S "\"serverZones\":{"

#if (NGX_HTTP_CACHE)
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_SERVER "\"%V\":{"               \
    "\"requestCounter\":%uA,"                                                  \
    "\"inBytes\":%uA,"                                                         \
    "\"outBytes\":%uA,"                                                        \
    "\"responses\":{"                                                          \
    "\"1xx\":%uA,"                                                             \
    "\"2xx\":%uA,"                                                             \
    "\"3xx\":%uA,"                                                             \
    "\"4xx\":%uA,"                                                             \
    "\"502\":%uA,"                                                             \
    "\"503\":%uA,"                                                             \
    "\"504\":%uA,"                                                             \
    "\"5xx\":%uA,"                                                             \
    "\"miss\":%uA,"                                                            \
    "\"bypass\":%uA,"                                                          \
    "\"expired\":%uA,"                                                         \
    "\"stale\":%uA,"                                                           \
    "\"updating\":%uA,"                                                        \
    "\"revalidated\":%uA,"                                                     \
    "\"hit\":%uA,"                                                             \
    "\"scarce\":%uA"                                                           \
    "},"                                                                       \
    "\"requestMsec\":%M,"                                                      \
    "\"requestMsecs\":{"                                                       \
    "\"times\":[%s],"                                                          \
    "\"msecs\":[%s]"                                                           \
    "},"                                                                       \
    "\"overCounts\":{"                                                         \
    "\"maxIntegerSize\":%s,"                                                   \
    "\"requestCounter\":%uA,"                                                  \
    "\"inBytes\":%uA,"                                                         \
    "\"outBytes\":%uA,"                                                        \
    "\"1xx\":%uA,"                                                             \
    "\"2xx\":%uA,"                                                             \
    "\"3xx\":%uA,"                                                             \
    "\"4xx\":%uA,"                                                             \
    "\"502\":%uA,"                                                             \
    "\"503\":%uA,"                                                             \
    "\"504\":%uA,"                                                             \
    "\"5xx\":%uA,"                                                             \
    "\"miss\":%uA,"                                                            \
    "\"bypass\":%uA,"                                                          \
    "\"expired\":%uA,"                                                         \
    "\"stale\":%uA,"                                                           \
    "\"updating\":%uA,"                                                        \
    "\"revalidated\":%uA,"                                                     \
    "\"hit\":%uA,"                                                             \
    "\"scarce\":%uA"                                                           \
    "}"                                                                        \
    "},"
#else
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_SERVER "\"%V\":{"               \
    "\"requestCounter\":%uA,"                                                  \
    "\"inBytes\":%uA,"                                                         \
    "\"outBytes\":%uA,"                                                        \
    "\"responses\":{"                                                          \
    "\"1xx\":%uA,"                                                             \
    "\"2xx\":%uA,"                                                             \
    "\"3xx\":%uA,"                                                             \
    "\"4xx\":%uA,"                                                             \
    "\"502\":%uA,"                                                             \
    "\"503\":%uA,"                                                             \
    "\"504\":%uA,"                                                             \
    "\"5xx\":%uA"                                                              \
    "},"                                                                       \
    "\"requestMsec\":%M,"                                                      \
    "\"requestMsecs\":{"                                                       \
    "\"times\":[%s],"                                                          \
    "\"msecs\":[%s]"                                                           \
    "},"                                                                       \
    "\"overCounts\":{"                                                         \
    "\"maxIntegerSize\":%s,"                                                   \
    "\"requestCounter\":%uA,"                                                  \
    "\"inBytes\":%uA,"                                                         \
    "\"outBytes\":%uA,"                                                        \
    "\"1xx\":%uA,"                                                             \
    "\"2xx\":%uA,"                                                             \
    "\"3xx\":%uA,"                                                             \
    "\"4xx\":%uA,"                                                             \
    "\"502\":%uA,"                                                             \
    "\"503\":%uA,"                                                             \
    "\"504\":%uA,"                                                             \
    "\"5xx\":%uA"                                                              \
    "}"                                                                        \
    "},"
#endif

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_FILTER_S "\"filterZones\":{"

#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_UPSTREAM_S "\"upstreamZones\":{"
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_UPSTREAM "{\"server\":\"%V\","  \
    "\"requestCounter\":%uA,"                                                  \
    "\"inBytes\":%uA,"                                                         \
    "\"outBytes\":%uA,"                                                        \
    "\"responses\":{"                                                          \
    "\"1xx\":%uA,"                                                             \
    "\"2xx\":%uA,"                                                             \
    "\"3xx\":%uA,"                                                             \
    "\"4xx\":%uA,"                                                             \
    "\"502\":%uA,"                                                             \
    "\"503\":%uA,"                                                             \
    "\"504\":%uA,"                                                             \
    "\"5xx\":%uA"                                                              \
    "},"                                                                       \
    "\"requestMsec\":%M,"                                                      \
    "\"requestMsecs\":{"                                                       \
    "\"times\":[%s],"                                                          \
    "\"msecs\":[%s]"                                                           \
    "},"                                                                       \
    "\"responseMsec\":%M,"                                                     \
    "\"responseMsecs\":{"                                                      \
    "\"times\":[%s],"                                                          \
    "\"msecs\":[%s]"                                                           \
    "},"                                                                       \
    "\"weight\":%ui,"                                                          \
    "\"maxFails\":%ui,"                                                        \
    "\"failTimeout\":%T,"                                                      \
    "\"backup\":%s,"                                                           \
    "\"down\":%s,"                                                             \
    "\"overCounts\":{"                                                         \
    "\"maxIntegerSize\":%s,"                                                   \
    "\"requestCounter\":%uA,"                                                  \
    "\"inBytes\":%uA,"                                                         \
    "\"outBytes\":%uA,"                                                        \
    "\"1xx\":%uA,"                                                             \
    "\"2xx\":%uA,"                                                             \
    "\"3xx\":%uA,"                                                             \
    "\"4xx\":%uA,"                                                             \
    "\"502\":%uA,"                                                             \
    "\"503\":%uA,"                                                             \
    "\"504\":%uA,"                                                             \
    "\"5xx\":%uA"                                                              \
    "}"                                                                        \
    "},"

#if (NGX_HTTP_CACHE)
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_CACHE_S "\"cacheZones\":{"
#define NGX_HTTP_VHOST_TRAFFIC_STATUS_JSON_FMT_CACHE "\"%V\":{"                \
    "\"maxSize\":%uA,"                                                         \
    "\"usedSize\":%uA,"                                                        \
    "\"inBytes\":%uA,"                                                         \
    "\"outBytes\":%uA,"                                                        \
    "\"responses\":{"                                                          \
    "\"miss\":%uA,"                                                            \
    "\"bypass\":%uA,"                                                          \
    "\"expired\":%uA,"                                                         \
    "\"stale\":%uA,"                                                           \
    "\"updating\":%uA,"                                                        \
    "\"revalidated\":%uA,"                                                     \
    "\"hit\":%uA,"                                                             \
    "\"scarce\":%uA"                                                           \
    "},"                                                                       \
    "\"overCounts\":{"                                                         \
    "\"maxIntegerSize\":%s,"                                                   \
    "\"inBytes\":%uA,"                                                         \
    "\"outBytes\":%uA,"                                                        \
    "\"miss\":%uA,"                                                            \
    "\"bypass\":%uA,"                                                          \
    "\"expired\":%uA,"                                                         \
    "\"stale\":%uA,"                                                           \
    "\"updating\":%uA,"                                                        \
    "\"revalidated\":%uA,"                                                     \
    "\"hit\":%uA,"                                                             \
    "\"scarce\":%uA"                                                           \
    "}"                                                                        \
    "},"
#endif

#define ngx_http_vhost_traffic_status_add_rc(s, n) {                           \
    if(s < 200) {n->stat_1xx_counter++;}                                       \
    else if(s < 300) {n->stat_2xx_counter++;}                                  \
    else if(s < 400) {n->stat_3xx_counter++;}                                  \
    else if(s < 500) {n->stat_4xx_counter++;}                                  \
    else if(s == 502) {n->stat_502_counter++;}                                  \
    else if(s == 503) {n->stat_503_counter++;}                                  \
    else if(s == 504) {n->stat_504_counter++;}                                  \
    else {n->stat_5xx_counter++;}                                              \
}

#if (NGX_HTTP_CACHE)

#if !defined(nginx_version) || nginx_version < 1005007
#define ngx_http_vhost_traffic_status_add_cc(s, n) {                           \
    if(s == NGX_HTTP_CACHE_MISS) {n->stat_cache_miss_counter++;}               \
    else if(s == NGX_HTTP_CACHE_BYPASS) {n->stat_cache_bypass_counter++;}      \
    else if(s == NGX_HTTP_CACHE_EXPIRED) {n->stat_cache_expired_counter++;}    \
    else if(s == NGX_HTTP_CACHE_STALE) {n->stat_cache_stale_counter++;}        \
    else if(s == NGX_HTTP_CACHE_UPDATING) {n->stat_cache_updating_counter++;}  \
    else if(s == NGX_HTTP_CACHE_HIT) {n->stat_cache_hit_counter++;}            \
    else if(s == NGX_HTTP_CACHE_SCARCE) {n->stat_cache_scarce_counter++;}      \
}
#else
#define ngx_http_vhost_traffic_status_add_cc(s, n) {                           \
    if(s == NGX_HTTP_CACHE_MISS) {                                             \
        n->stat_cache_miss_counter++;                                          \
    }                                                                          \
    else if(s == NGX_HTTP_CACHE_BYPASS) {                                      \
        n->stat_cache_bypass_counter++;                                        \
    }                                                                          \
    else if(s == NGX_HTTP_CACHE_EXPIRED) {                                     \
        n->stat_cache_expired_counter++;                                       \
    }                                                                          \
    else if(s == NGX_HTTP_CACHE_STALE) {                                       \
        n->stat_cache_stale_counter++;                                         \
    }                                                                          \
    else if(s == NGX_HTTP_CACHE_UPDATING) {                                    \
        n->stat_cache_updating_counter++;                                      \
    }                                                                          \
    else if(s == NGX_HTTP_CACHE_REVALIDATED) {                                 \
        n->stat_cache_revalidated_counter++;                                   \
    }                                                                          \
    else if(s == NGX_HTTP_CACHE_HIT) {                                         \
        n->stat_cache_hit_counter++;                                           \
    }                                                                          \
    else if(s == NGX_HTTP_CACHE_SCARCE) {                                      \
        n->stat_cache_scarce_counter++;                                        \
    }                                                                          \
}
#endif

#endif

#if (NGX_HTTP_CACHE)
#define ngx_http_vhost_traffic_status_add_oc(o, c) {                           \
    if (o->stat_request_counter > c->stat_request_counter) {                   \
        c->stat_request_counter_oc++;                                          \
    }                                                                          \
    if (o->stat_in_bytes > c->stat_in_bytes) {                                 \
        c->stat_in_bytes_oc++;                                                 \
    }                                                                          \
    if (o->stat_out_bytes > c->stat_out_bytes) {                               \
        c->stat_out_bytes_oc++;                                                \
    }                                                                          \
    if (o->stat_1xx_counter > c->stat_1xx_counter) {                           \
        c->stat_1xx_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_2xx_counter > c->stat_2xx_counter) {                           \
        c->stat_2xx_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_3xx_counter > c->stat_3xx_counter) {                           \
        c->stat_3xx_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_4xx_counter > c->stat_4xx_counter) {                           \
        c->stat_4xx_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_502_counter > c->stat_502_counter) {                           \
        c->stat_502_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_503_counter > c->stat_503_counter) {                           \
        c->stat_503_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_504_counter > c->stat_504_counter) {                           \
        c->stat_504_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_5xx_counter > c->stat_5xx_counter) {                           \
        c->stat_5xx_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_cache_miss_counter > c->stat_cache_miss_counter) {             \
        c->stat_cache_miss_counter_oc++;                                       \
    }                                                                          \
    if (o->stat_cache_bypass_counter > c->stat_cache_bypass_counter) {         \
        c->stat_cache_bypass_counter_oc++;                                     \
    }                                                                          \
    if (o->stat_cache_expired_counter > c->stat_cache_expired_counter) {       \
        c->stat_cache_expired_counter_oc++;                                    \
    }                                                                          \
    if (o->stat_cache_stale_counter > c->stat_cache_stale_counter) {           \
        c->stat_cache_stale_counter_oc++;                                      \
    }                                                                          \
    if (o->stat_cache_updating_counter > c->stat_cache_updating_counter) {     \
        c->stat_cache_updating_counter_oc++;                                   \
    }                                                                          \
    if (o->stat_cache_revalidated_counter > c->stat_cache_revalidated_counter) \
    {                                                                          \
        c->stat_cache_revalidated_counter_oc++;                                \
    }                                                                          \
    if (o->stat_cache_hit_counter > c->stat_cache_hit_counter) {               \
        c->stat_cache_hit_counter_oc++;                                        \
    }                                                                          \
    if (o->stat_cache_scarce_counter > c->stat_cache_scarce_counter) {         \
        c->stat_cache_scarce_counter_oc++;                                     \
    }                                                                          \
}
#else
#define ngx_http_vhost_traffic_status_add_oc(o, c) {                           \
    if (o->stat_request_counter > c->stat_request_counter) {                   \
        c->stat_request_counter_oc++;                                          \
    }                                                                          \
    if (o->stat_in_bytes > c->stat_in_bytes) {                                 \
        c->stat_in_bytes_oc++;                                                 \
    }                                                                          \
    if (o->stat_out_bytes > c->stat_out_bytes) {                               \
        c->stat_out_bytes_oc++;                                                \
    }                                                                          \
    if (o->stat_1xx_counter > c->stat_1xx_counter) {                           \
        c->stat_1xx_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_2xx_counter > c->stat_2xx_counter) {                           \
        c->stat_2xx_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_3xx_counter > c->stat_3xx_counter) {                           \
        c->stat_3xx_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_4xx_counter > c->stat_4xx_counter) {                           \
        c->stat_4xx_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_502_counter > c->stat_502_counter) {                           \
        c->stat_502_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_503_counter > c->stat_503_counter) {                           \
        c->stat_503_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_504_counter > c->stat_504_counter) {                           \
        c->stat_504_counter_oc++;                                              \
    }                                                                          \
    if (o->stat_5xx_counter > c->stat_5xx_counter) {                           \
        c->stat_5xx_counter_oc++;                                              \
    }                                                                          \
}
#endif

#define ngx_http_vhost_traffic_status_group_to_string(n) (u_char *) (          \
    (n > 4)                                                                    \
    ? NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAMS                                  \
    : NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAMS + 3 * n                          \
)

#define ngx_http_vhost_traffic_status_string_to_group(s) (unsigned) (          \
{                                                                              \
    unsigned n = NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_NO;                    \
    if (*s == 'N' && *(s + 1) == 'O') {                                        \
        n = NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_NO;                         \
    } else if (*s == 'U' && *(s + 1) == 'A') {                                 \
        n = NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_UA;                         \
    } else if (*s == 'U' && *(s + 1) == 'G') {                                 \
        n = NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_UG;                         \
    } else if (*s == 'C' && *(s + 1) == 'C') {                                 \
        n = NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_CC;                         \
    } else if (*s == 'F' && *(s + 1) == 'G') {                                 \
        n = NGX_HTTP_VHOST_TRAFFIC_STATUS_UPSTREAM_FG;                         \
    }                                                                          \
    n;                                                                         \
}                                                                              \
)

#define ngx_http_vhost_traffic_status_max_integer (NGX_ATOMIC_T_LEN < 12)      \
    ? "4294967295"                                                             \
    : "18446744073709551615"

#define ngx_http_vhost_traffic_status_boolean_to_string(b) (b) ? "true" : "false"

#define ngx_http_vhost_traffic_status_triangle(n) (unsigned) (                 \
    n * (n + 1) / 2                                                            \
)


typedef struct {
    ngx_rbtree_t                           *rbtree;

    /* array of ngx_http_vhost_traffic_status_filter_t */
    ngx_array_t                            *filter_keys;

    /* array of ngx_http_vhost_traffic_status_limit_t */
    ngx_array_t                            *limit_traffics;

    /* array of ngx_http_vhost_traffic_status_limit_t */
    ngx_array_t                            *limit_filter_traffics;

    ngx_flag_t                              enable;
    ngx_flag_t                              filter_check_duplicate;
    ngx_flag_t                              limit_check_duplicate;
    ngx_shm_zone_t                         *shm_zone;
    ngx_str_t                               shm_name;
    ssize_t                                 shm_size;

    ngx_flag_t                              dump;
    ngx_str_t                               dump_file;
    ngx_msec_t                              dump_period;
    ngx_event_t                             dump_event;
} ngx_http_vhost_traffic_status_ctx_t;


typedef struct {
    ngx_shm_zone_t                         *shm_zone;
    ngx_str_t                               shm_name;
    ngx_flag_t                              enable;
    ngx_flag_t                              filter;
    ngx_flag_t                              filter_host;
    ngx_flag_t                              filter_check_duplicate;

    /* array of ngx_http_vhost_traffic_status_filter_t */
    ngx_array_t                            *filter_keys;

    /* array of ngx_http_vhost_traffic_status_filter_variable_t */
    ngx_array_t                            *filter_vars;

    ngx_flag_t                              limit;
    ngx_flag_t                              limit_check_duplicate;

    /* array of ngx_http_vhost_traffic_status_limit_t */
    ngx_array_t                            *limit_traffics;

    /* array of ngx_http_vhost_traffic_status_limit_t */
    ngx_array_t                            *limit_filter_traffics;

    ngx_http_vhost_traffic_status_node_t    stats;
    ngx_msec_t                              start_msec;
    ngx_flag_t                              format;
    ngx_str_t                               jsonp;
    ngx_str_t                               sum_key;

    ngx_flag_t                              average_method;
    ngx_msec_t                              average_period;

    ngx_flag_t                              bypass_limit;
    ngx_flag_t                              bypass_stats;

    ngx_rbtree_node_t                     **node_caches;
} ngx_http_vhost_traffic_status_loc_conf_t;


ngx_msec_int_t ngx_http_vhost_traffic_status_request_time(ngx_http_request_t *r);
ngx_msec_int_t ngx_http_vhost_traffic_status_upstream_response_time(ngx_http_request_t *r);

extern ngx_module_t ngx_http_vhost_traffic_status_module;


#endif /* _NGX_HTTP_VTS_MODULE_H_INCLUDED_ */

/* vi:set ft=c ts=4 sw=4 et fdm=marker: */
