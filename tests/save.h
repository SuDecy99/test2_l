#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>

extern "C++" {
#include "common.h"
#include "text.h"
#include "_text.h"
}

TEST(save_fun, multiple_lines)
{
    text txt = create_text();
    txt->lines->push_back("line 0\n");
    txt->lines->push_back("line 1\n");
    txt->lines->push_back("line 2\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;
    save(txt, "save_fun.test.txt");

    text txt2 = create_text();
    load(txt2, "save_fun.test.txt");

    EXPECT_EQ(txt->lines->size(), txt2->lines->size());

    string* txt_arr = new string[txt->lines->size()];
    string* txt2_arr = new string[txt2->lines->size()];

    copy(txt->lines->begin(), txt->lines->end(), txt_arr);
    copy(txt2->lines->begin(), txt2->lines->end(), txt2_arr);

    for(unsigned int i = 0; i < txt->lines->size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}

TEST(save_fun, one_line)
{
    text txt = create_text();
    txt->lines->push_back("line 0\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;
    save(txt, "save_fun.test.txt");

    text txt2 = create_text();
    load(txt2, "save_fun.test.txt");

    EXPECT_EQ(txt->lines->size(), txt2->lines->size());

    string* txt_arr = new string[txt->lines->size()];
    string* txt2_arr = new string[txt2->lines->size()];

    copy(txt->lines->begin(), txt->lines->end(), txt_arr);
    copy(txt2->lines->begin(), txt2->lines->end(), txt2_arr);

    for(unsigned int i = 0; i < txt->lines->size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}

TEST(save_fun, empty_file)
{
    text txt = create_text();
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;
    save(txt, "save_fun.test.txt");

    text txt2 = create_text();
    load(txt2, "save_fun.test.txt");

    EXPECT_EQ(txt->lines->size(), txt2->lines->size());

    string* txt_arr = new string[txt->lines->size()];
    string* txt2_arr = new string[txt2->lines->size()];

    copy(txt->lines->begin(), txt->lines->end(), txt_arr);
    copy(txt2->lines->begin(), txt2->lines->end(), txt2_arr);

    for(unsigned int i = 0; i < txt->lines->size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}
