#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "common.h"
#include "text.h"
#include "_text.h"
}

TEST(add_line_after, normal)
{
    text txt = create_text();
    txt->lines->push_back("line 0\n");
    txt->lines->push_back("line 1\n");
    txt->lines->push_back("line 2\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    add_line_after(txt, 1, "new line\n");

    string* txt_arr = new string[txt->lines->size()];
    copy(txt->lines->begin(), txt->lines->end(), txt_arr);

    EXPECT_EQ(txt->lines->size(), 4);
    EXPECT_STREQ(txt_arr[0].c_str(), "line 0\n");
    EXPECT_STREQ(txt_arr[1].c_str(), "line 1\n");
    EXPECT_STREQ(txt_arr[2].c_str(), "new line\n");
    EXPECT_STREQ(txt_arr[3].c_str(), "line 2\n");

    free(txt);
}

TEST(add_line_after, empty_text)
{
    text txt = create_text();
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    add_line_after(txt, 0, "new line\n");

    string* txt_arr = new string[txt->lines->size()];
    copy(txt->lines->begin(), txt->lines->end(), txt_arr);

    EXPECT_EQ(txt->lines->size(), 1);
    EXPECT_STREQ(txt_arr[0].c_str(), "new line\n");

    free(txt);
}

TEST(add_line_after, to_big)
{
    text txt = create_text();
    txt->lines->push_back("line 0\n");
    txt->lines->push_back("line 1\n");
    txt->lines->push_back("line 2\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    add_line_after(txt, 10, "new line\n");

    string* txt_arr = new string[txt->lines->size()];
    copy(txt->lines->begin(), txt->lines->end(), txt_arr);

    EXPECT_EQ(txt->lines->size(), 4);
    EXPECT_STREQ(txt_arr[0].c_str(), "line 0\n");
    EXPECT_STREQ(txt_arr[1].c_str(), "line 1\n");
    EXPECT_STREQ(txt_arr[2].c_str(), "line 2\n");

    // при выходе за границы добавляется в конец файла
    EXPECT_STREQ(txt_arr[3].c_str(), "new line\n");

    free(txt);
}
