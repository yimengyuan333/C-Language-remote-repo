#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} QueryParam;

typedef struct {
    char *path;
    QueryParam *params;
    int count;
} ParsedURL;

// 检查 URL 格式是否合法
int is_valid_url(const char *url)
{
    if (url == NULL) return 0;
    return strncmp(url, "http://", 7) == 0;
}

// 解析 URL
ParsedURL *parse_url(const char *url)
{
    if (!is_valid_url(url)) {
        return NULL;
    }

    ParsedURL *result = malloc(sizeof(ParsedURL));
    if (result == NULL) {
        return NULL;
    }

    // 1. 找到 '?' 的位置，分离路径和查询字符串
    char *qmark = strchr(url, '?');
    if (qmark == NULL) {
        // 没有查询字符串，只有路径
        result->path = strdup(url);
        result->params = NULL;
        result->count = 0;
        return result;
    }

    // 2. 提取路径（跳过 "http://" 和域名）
    char *path_start = strchr(url + 7, '/');
    if (path_start == NULL) {
        // 没有路径（如 "http://example.com"）
        result->path = strdup("/");
    } else {
        int path_len = qmark - path_start;
        result->path = malloc(path_len + 1);
        strncpy(result->path, path_start, path_len);
        result->path[path_len] = '\0';
    }

    // 3. 提取查询字符串
    char *query = strdup(qmark + 1);
    if (query == NULL) {
        free(result->path);
        free(result);
        return NULL;
    }

    // 4. 统计键值对数量
    int count = 0;
    char *temp = query;
    while (*temp) {
        if (*temp == '=') count++;
        temp++;
    }

    if (count == 0) {
        result->params = NULL;
        result->count = 0;
        free(query);
        return result;
    }

    // 5. 分配键值对数组
    result->params = malloc(count * sizeof(QueryParam));
    if (result->params == NULL) {
        free(result->path);
        free(query);
        free(result);
        return NULL;
    }

    // 6. 用 strtok 分割键值对
    char *token = strtok(query, "&");
    int index = 0;
    while (token != NULL && index < count) {
        char *eq = strchr(token, '=');
        if (eq != NULL) {
            result->params[index].key = malloc(eq - token + 1);
            strncpy(result->params[index].key, token, eq - token);
            result->params[index].key[eq - token] = '\0';
            result->params[index].value = strdup(eq + 1);
            index++;
        }
        token = strtok(NULL, "&");
    }
    result->count = index;
    free(query);

    return result;
}

// 打印解析结果
void print_parsed_url(const ParsedURL *url)
{
    if (url == NULL) return;
    printf("Path: %s\n", url->path);
    printf("Query Params (%d):\n", url->count);
    for (int i = 0; i < url->count; i++) {
        printf("  %s = %s\n", url->params[i].key, url->params[i].value);
    }
}

// 释放内存
void free_parsed_url(ParsedURL *url)
{
    if (url == NULL) return;
    free(url->path);
    for (int i = 0; i < url->count; i++) {
        free(url->params[i].key);
        free(url->params[i].value);
    }
    free(url->params);
    free(url);
}

int main(void)
{
    const char *url1 = "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=";
    const char *url2 = "http://www.baidu.com/s?wd=linux&cl=3";

    ParsedURL *p1 = parse_url(url1);
    print_parsed_url(p1);
    free_parsed_url(p1);

    printf("\n");

    ParsedURL *p2 = parse_url(url2);
    print_parsed_url(p2);
    free_parsed_url(p2);

    return 0;
}