#ifndef TEMPORARY_FILE_30_DIAS_DE_C_I
#define TEMPORARY_FILE_30_DIAS_DE_C_I

#include <cstdio>
#include <iostream>
#include <boost/filesystem/exception.hpp>
#include <boost/filesystem/operations.hpp>

class temporary_file
{
public:
    temporary_file()
    {
        try
        {
            m_path = boost::filesystem::temp_directory_path();
            m_path /= boost::filesystem::unique_path(m_tmp_pattern);

            m_file = fopen(m_path.c_str(), "w+x");
        }
        catch (boost::filesystem::filesystem_error& err)
        {
            // Error handled by caller via is_open().
            std::cerr << "Failed to create temporary file.\n"
                      << "Error: "
                      << err.what()
                      << std::endl;
        }
    }

    temporary_file(const temporary_file&) = delete;
    temporary_file(temporary_file&&) = delete;

    temporary_file& operator=(const temporary_file&) = delete;
    temporary_file& operator=(temporary_file&& other) = delete;

    ~temporary_file()
    {
        if (m_file != NULL)
        {
            std::fclose(m_file);
            std::remove(m_path.c_str());

            m_file = NULL;
        }
    }

    bool is_open() const
    {
        return (m_file != NULL);
    }

    bool reopen()
    {
        if (is_open())
        {
            m_file = std::freopen(m_path.c_str(), "w+", m_file);
        }

        return is_open();
    }

    std::FILE* get_file()
    {
        return m_file;
    }

private:
    std::FILE* m_file = NULL;
    boost::filesystem::path m_path;

    static constexpr auto m_tmp_pattern = "io-30dc_%%%%-%%%%-%%%%-%%%%";
};

#endif // TEMPORARY_FILE_30_DIAS_DE_C_I
