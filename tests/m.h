#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "common.h"
#include "text.h"
#include "_text.h"
}

TEST(move, normal)
{
    text txt = create_text();
    txt->lines->push_back("line 0\n");
    txt->lines->push_back("line 1\n");
    txt->lines->push_back("line 2\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    m(txt, 0, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt, 1, 3);
    EXPECT_EQ(txt->cursor->line_num, 1);
    EXPECT_EQ(txt->cursor->position, 3);

    free(txt);
}

TEST(move, too_big)
{
    text txt = create_text();
    txt->lines->push_back("line 0\n");
    txt->lines->push_back("line 1\n");
    txt->lines->push_back("line 2\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    m(txt, 0, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, 100, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, 100, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}
