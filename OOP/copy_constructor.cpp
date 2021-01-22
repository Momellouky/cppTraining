#include <iostream> 
#include <cstring>

class String
{
    private:
        char* m_Buffer; 
        unsigned int m_size;
        
    public:
        String(const char* string)
        {
            m_size = strlen(string); 
            m_Buffer = new char[m_size + 1]; 
            memcpy(m_Buffer, string, m_size + 1);
            m_Buffer[m_size] = 0; 
        }
        
        String(const String& other): m_size(other.m_size)
        {
            m_Buffer = new char[m_size + 1];
            memcpy(m_Buffer, other.m_Buffer, m_size + 1);
        }
        
        ~String()
        {
            delete[] m_Buffer; 
        }
        
        char& operator[](unsigned int index)
        {
            return m_Buffer[index]; 
        }
        
        
        friend std::ostream& operator<<(std::ostream& stream, const String& string); 
        
        
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer; 
    return stream; 
}

int main()
{
    String name     = "Mohamed Mellouky";  
    String github   = "Github is awsome"; // Deep copying ( copy constructor)

    // name and github have different memory location. 
    
    std::cout << name << std::endl; 
    std::cout << github << std::endl; 
    
    // if we change a String object, the change doesn't affect the other object 
    github[0] = 'g'; 
    
    std::cout << name << std::endl; // note that name[0] remains 'M'
    std::cout << github << std::endl; 
    
    
    return 0;
}
