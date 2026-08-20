#include<stdio.h>
#include<string.h>

#define MAXFILE_LINE 128

char *get_a_line(const char *filename, int n) {
    static char line[MAXFILE_LINE];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    int line_num = 0;
    
    while (fgets(line, sizeof(line), fp) != NULL) {         //注意，fgets不是固定每次从源文件读127个字符出来然后后面加\0
        line_num++;                                         //而是遇到\n或者EOF就停了，调用就到此为止了，如果127个了还没有换行或出错
        if (line_num == n) {                                //那样确实会在127处截止，把127个拿满
            fclose(fp);
            char *p = line;
            
            while (*p == ' ' || *p == '\t') {               //在get_a_line的时候就手把行首空白符删了
                p++;
            }
            //接下来这一步是把代码往左移，让line指向的是真正的开头
            if (p != line) {                                //如果行首由空白符，导致p != line
                char *dst = line;                           //为了让line直接指向“真正的开头”，需要把p后面的内容复制到line的起始位置
                while (*p) {                                //p在前面往右走，dst就在后面跟着往右走
                *dst++ = *p++;
                }
                *dst = '\0';
            }

            char *last_c = strchr(line, '\n');
            if(last_c != NULL)
                *last_c = '\0';                             //别忘了解引用

            return line;
        }
    }
    
    fclose(fp);
    return NULL;
}

int is_comment(char *line){
    if(line[0] == ';')
        return 1;
    return 0;
}

int is_section(char *line){
    if(line[0] == '[')
        return 1;
    return 0;
}

int is_key_value_pair(char *line){
    if(strchr(line, '=') != NULL)
        return 1;
    return 0;
}

int main(void){
    
    FILE *fp_out = fopen("XML.txt", "w");

    if (fp_out == NULL) {
    perror("fopen XML.txt");
    return 1;
    }

    int line_num = 1;
    char *this_line;

    while((this_line = get_a_line("INI.txt", line_num)) != NULL){
        line_num++;

        if(is_comment(this_line)){
            char *start = this_line + 1;
            while (*start == ' ' || *start == '\t') {
                start++;
            }
            fprintf(fp_out, "<!-- %s -->\n", start);
        }
        else if (is_section(this_line)) {
            // Section：[section] → <section>
            char *p = this_line + 1;
            char *end = strchr(p, ']');
            if (end != NULL) {
                *end = '\0';
                fprintf(fp_out, "<%s>\n", p);
            }
        }
        else if (is_key_value_pair(this_line)) {

            char *eq = strchr(this_line, '=');                  //依旧用strchr查找字符'='
            if (eq != NULL) {
                char key[64];
                strncpy(key, this_line, eq - this_line);        //eq - this_line表达的是从找到'='的地方到开头的字符个数，也就是键的长度，要传给strncpy的n使用
                key[eq - this_line] = '\0';                     //后面不用的地方截掉

                char *value = eq + 1;
                while (*value == ' ' || *value == '\t') {
                    value++;
                }

                // 去掉 key 末尾空白
                char *k = key + strlen(key) - 1;                //别迷，这个地方key指的是key的开头位置，加上strlen(key)-1应该是末尾位置，应该是那个\0
                while (k > key && (*k == ' ' || *k == '\t')) {  //在key的真实值范围内，可能会有空格和制表符，是没用的字符，要消掉
                    *k = '\0';
                    k--;
                }

                fprintf(fp_out, "    <%s>%s</%s>\n", key, value, key);
            }
        }

    }
    fclose(fp_out);
    return 0;
}