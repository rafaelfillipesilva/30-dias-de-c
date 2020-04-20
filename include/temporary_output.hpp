#ifndef TEMPORARY_OUTPUT_30_DIAS_DE_C_I
#define TEMPORARY_OUTPUT_30_DIAS_DE_C_I

#include <cstdio>

class temporary_output
{
public:
    temporary_output()
    {
        m_file = std::tmpfile();
    }

    ~temporary_output()
    {
        if (m_file != nullptr)
        {
            std::fclose(m_file);
        }
    }

    temporary_output(const temporary_output&) = delete;
    temporary_output(temporary_output&&) = delete;

    temporary_output& operator=(const temporary_output&) = delete;
    temporary_output& operator=(temporary_output&&) = delete;

    FILE* file() const { return m_file; }

    bool is_open() const { return (m_file != nullptr); }

private:
    std::FILE* m_file = nullptr;
};

#endif // TEMPORARY_OUTPUT_30_DIAS_DE_C_I
