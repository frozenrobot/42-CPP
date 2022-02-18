#include "Number.hpp"

Number::Number(std::string input) : str(input)
{
    for (int i = 1; i <= 4; i++)
        setFlag(i, 0);
    return ;
}

Number::~Number(void)
{
    return ;
}

void Number::parse(void)
{
    std::stringstream s;
    int length = this->str.length();
    int i = 0;

    if (length == 1 && !std::isdigit(this->str[0]))
	{
		this->type = 1;
		this->aschar = this->str[0];
		return ;
	}
    if (this->str == "inff" || this->str == "-inff" || this->str == "+inff" || this->str == "nanf")
    {
        this->asfloat = atof(this->str.c_str());
        this->type = 4;
        return ;
    }
    else if (this->str == "inf" ||  this->str == "-inf" || this->str == "+inf" || this->str == "nan")
    {
        this->asdouble = atof(this->str.c_str());
        this->type = 3;
        return ;
    }
    if (this->str[0] == '+' || this->str[0] == '-')
    {
		s << str[i];
        i++;
    }
	this->type = 2;
    while (i < length)
    {
        if (this->type != 3 && this->str[i] == '.')
		{
			this->type = 3;
			s << str[i];
		}
		else if (this->str[i] == 'e' && i < length - 1 && (this->str[i + 1] == '+' || this->str[i + 1] == '-' || std::isdigit(this->str[i + 1])))
		{
			s << str[i] << str[i + 1];
			i++;
			this->type = 3;
		}
		else if (this->str[i] == 'f' && i == length - 1 && this->type == 3)
			this->type = 4;
		else if (!std::isdigit(this->str[i]))
		{
			this->type = 0;
			break ;
		}
		else
			s << str[i];
        i++;
    }
    if (this->type == 4)
        s >> this->asfloat;
    else if (this->type == 3)
        s >> this->asdouble;
    else if (this->type == 2)
    {
        long longint;
        s >> longint;
        if (longint > std::numeric_limits<int>::max() || longint < std::numeric_limits<int>::min())
            this->type = 0;
        else
            this->asint = longint;
    }
}

void Number::setFlag(int type, int flag) //1=impossible, 2=non-displayable
{
    this->flags[type - 1] = flag;
}

int Number::getFlag(int type)
{
    return (this->flags[type - 1]);
}

bool Number::hasFlag(int type, int flag)
{
    if (this->flags[type - 1] == flag)
        return (true);
    return (false);
}

void Number::convert(void)
{
    switch (this->type)
    {
        case 1:
            this->asint = static_cast<int>(this->aschar);
            this->asfloat = static_cast<float>(this->aschar);
            this->asdouble = static_cast<double>(this->aschar);
            break;
        case 2:
            if (this->asint > 126 || this->asint < 32)
                setFlag(1, 2);
            else
                this->aschar = static_cast<char>(this->asint);
            this->asfloat = static_cast<float>(this->asint);
            this->asdouble = static_cast<double>(this->asint);
            break;
        case 3:
            // if (std::isnan(this->asdouble) || std::isinf(this->asdouble))
            //     setFlag(1, 1);
            if (this->asdouble > 126.0 || this->asdouble < 32.0)
                setFlag(1, 2);
            else
                this->aschar = static_cast<char>(static_cast<int>(this->asdouble));
            this->asfloat = static_cast<float>(this->asdouble);
            this->asint = static_cast<int>(this->asdouble);
            // if (std::isnan(this->asdouble) || std::isinf(this->asdouble) || this->asdouble > std::numeric_limits<int>::max() || this->asdouble < std::numeric_limits<int>::min())
            //     this->setFlag(2, 1);
            break;
        case 4:
            // if (std::isnan(this->asfloat) || std::isinf(this->asfloat))
            //     setFlag(1, 1);
            if (this->asfloat > 126.0f || this->asfloat < 32.0f)
                setFlag(1, 2);
            else
                this->aschar = static_cast<char>(static_cast<int>(this->asfloat));
            this->asint = static_cast<int>(this->asfloat);
            this->asdouble = static_cast<double>(this->asfloat);
            // if (std::isnan(this->asfloat) || std::isinf(this->asfloat) || this->asfloat > std::numeric_limits<int>::max() || this->asfloat < std::numeric_limits<int>::min())
            //     this->setFlag(2, 1);
    }
    if (this->type == 1 && (this->aschar < 32 || this->aschar > 126))
        this->setFlag(1, 2);
    // std::cout << this->type << std::endl;
}

void Number::outputInfo(void)
{
    this->parse();
    this->convert();
    if (this->str == "inff" || this->str == "-inff" || this->str == "+inff" || this->str == "nanf" || this->str == "inf" ||  this->str == "-inf" || this->str == "+inf" || this->str == "nan")
    {
        setFlag(1, 1);
        setFlag(2, 1);
    }
    if (this->type == 0)
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    std::cout << "char: ";
    if (hasFlag(1, 2))
        std::cout << "Non displayable" << std::endl;
    else if (hasFlag(1, 1))
        std::cout << "impossible" << std::endl;
    else
        std::cout << "'" << this->aschar << "'" << std::endl;
    std::cout << "int: ";
    if (hasFlag(2, 1))
        std::cout << "impossible" << std::endl;
    else
        std::cout << this->asint << std::endl;
    std::cout << "float: " << this->asfloat;
    std::stringstream s;
    s << this->asfloat;
    std::string temp = s.str();
    if (!std::isnan(this->asfloat) && !std::isinf(this->asfloat) && temp.find('.') == std::string::npos)
        std::cout << ".0f\n";
    else
        std::cout << "f\n";
    std::cout << "double: " << this->asdouble;
    s.clear();
    s << this->asdouble;
    temp = s.str();
    if (!std::isnan(this->asdouble) && !std::isinf(this->asdouble) && temp.find('.') == std::string::npos)
        std::cout << ".0";
    std::cout << std::endl;
}