#include <gtest/gtest.h>
#include "headers/Stack.hpp"

// --- Empty stack tests ---

TEST(StackTest, EmptyOnInit)
{
    Stack<int> st;
    EXPECT_TRUE(st.empty());
    EXPECT_EQ(st.size(), 0u);
}

// --- Push and Top ---
TEST(StackTest, PushAndTop)
{
    Stack<int> st;
    st.push(10);
    EXPECT_FALSE(st.empty());
    EXPECT_EQ(st.size(), 1u);
    EXPECT_EQ(st.top(), 10);

    st.push(20);
    EXPECT_EQ(st.size(), 2u);
    EXPECT_EQ(st.top(), 20);
}

// --- Pop ---
TEST(StackTest, PopElement)
{
    Stack<int> st;
    st.push(5);
    st.push(15);

    EXPECT_EQ(st.top(), 15);
    st.pop();
    EXPECT_EQ(st.top(), 5);
    EXPECT_EQ(st.size(), 1u);

    st.pop();
    EXPECT_TRUE(st.empty());
}

// --- Copy constructor (deep copy) ---
TEST(StackTest, CopyConstructor)
{
    Stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);

    Stack<int> st2(st1); // copy constructor

    EXPECT_EQ(st2.size(), st1.size());

    EXPECT_EQ(st1.top(), st2.top());
    st1.pop();
    st2.pop();
    EXPECT_EQ(st1.top(), st2.top());
}

// --- Independence (modifications don’t affect each other) ---
TEST(StackTest, CopyIndependence)
{
    Stack<int> st1;
    st1.push(100);
    st1.push(200);

    Stack<int> st2(st1);

    st2.push(300);

    EXPECT_EQ(st1.size(), 2u);
    EXPECT_EQ(st2.size(), 3u); 
    EXPECT_EQ(st2.top(), 300);
}

TEST(StackComparisonTest, EqualStacks)
{
    Stack<int> s1;
    Stack<int> s2;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    s2.push(1);
    s2.push(2);
    s2.push(3);

    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 < s2);
}

TEST(StackComparisonTest, NotEqualStacks)
{
    Stack<int> s1;
    Stack<int> s2;

    s1.push(1);
    s1.push(2);

    s2.push(1);
    s2.push(3);

    EXPECT_FALSE(s1 == s2);
    EXPECT_TRUE(s1 < s2);
}

TEST(StackComparisonTest, DifferentSizes)
{
    Stack<int> s1;
    Stack<int> s2;

    s1.push(1);
    s1.push(2);

    s2.push(1);
    s2.push(2);
    s2.push(3);

    EXPECT_FALSE(s1 == s2);
    EXPECT_TRUE(s1 < s2); 
}

TEST(StackComparisonTest, LexicographicalOrder)
{
    Stack<int> s1;
    Stack<int> s2;

    s1.push(1);
    s1.push(4);

    s2.push(1);
    s2.push(5);

    EXPECT_TRUE(s1 < s2);
    EXPECT_FALSE(s1 == s2);
}

TEST(StackCopyTest, CopyEmptyStack)
{
    Stack<int> s1;
    Stack<int> s2(s1); // copy constructor

    EXPECT_TRUE(s2.empty());
    EXPECT_EQ(s2.size(), 0U);
}

TEST(StackCopyTest, CopyNonEmptyStack)
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    Stack<int> s2(s1); // copy constructor

    EXPECT_EQ(s1.size(), s2.size());

    Stack<int> tmp1 = s1;
    Stack<int> tmp2 = s2;
    while (!tmp1.empty()) {
        EXPECT_EQ(tmp1.top(), tmp2.top());
        tmp1.pop();
        tmp2.pop();
    }
}

// === Assignment operator tests ===
TEST(StackAssignTest, AssignEmptyStack)
{
    Stack<int> s1;
    Stack<int> s2;
    s2 = s1; 

    EXPECT_TRUE(s2.empty());
    EXPECT_EQ(s2.size(), 0U);
}

TEST(StackAssignTest, AssignNonEmptyStack)
{
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    Stack<int> s2;
    s2.push(1);  
    s2.push(2);

    s2 = s1; 

    EXPECT_EQ(s1.size(), s2.size());

    Stack<int> tmp1 = s1;
    Stack<int> tmp2 = s2;
    while (!tmp1.empty()) {
        EXPECT_EQ(tmp1.top(), tmp2.top());
        tmp1.pop();
        tmp2.pop();
    }
}

TEST(StackAssignTest, SelfAssignment)
{
    Stack<int> s;
    s.push(100);
    s.push(200);

    s = s; 
    
    EXPECT_EQ(s.size(), 2U);
    EXPECT_EQ(s.top(), 200);
    s.pop();
    EXPECT_EQ(s.top(), 100);
}

TEST(StackCompareTest, GreaterThan)
{
    Stack<int> s1;
    Stack<int> s2;

    s1.push(1);
    s1.push(2);
    s2.push(1);

    EXPECT_TRUE(s1 > s2);
    EXPECT_FALSE(s2 > s1);
}

// === operator>= tests ===
TEST(StackCompareTest, GreaterEqual)
{
    Stack<int> s1;
    Stack<int> s2;

    s1.push(5);
    s1.push(10);

    s2.push(5);
    s2.push(10);

    EXPECT_TRUE(s1 >= s2); 
    EXPECT_TRUE(s1 >= s2); 
    s2.push(1);
    EXPECT_FALSE(s1 >= s2);
    EXPECT_TRUE(s2 >= s1);
}

// === operator<= tests ===
TEST(StackCompareTest, LessEqual)
{
    Stack<int> s1;
    Stack<int> s2;

    s1.push(1);
    s2.push(1);
    s2.push(2);

    EXPECT_TRUE(s1 <= s2);
    EXPECT_FALSE(s2 <= s1);

    Stack<int> s3;
    s3.push(3);
    s3.push(4);

    Stack<int> s4;
    s4.push(3);
    s4.push(4);

    EXPECT_TRUE(s3 <= s4); 
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

