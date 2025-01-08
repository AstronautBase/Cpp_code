#ifndef EXCEPTION_H

#define EXCEPTION_H

#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <exception>
#include <cstdarg>
#include <cstring>

// Exception 类
class Exception : public std::exception
{
protected:
    std::string name;
    std::string content;

public:
    Exception(std::string name, std::string content) : name(name), content(content) {}
    virtual const char *what() const noexcept override
    {
        return content.c_str();
    }
    virtual std::string getSimpleMessage() const
    {
        return name;
    }
    virtual std::string getFormattedMessage() const
    {
        return name + ": " + content;
    }
};

// ClassException 类
class ClassException : public Exception
{
public:
    ClassException(std::string className, std::string content) : Exception(className, content) {}
    std::string getSimpleMessage() const override
    {
        return "[ClassException] " + name;
    }
    std::string getFormattedMessage() const override
    {
        return "ClassException (" + name + "): " + content;
    }
};

// MethodCallException 类
class MethodCallException : public Exception
{
private:
    std::string methodName;

public:
    MethodCallException(std::string className, std::string methodName, std::string content) : Exception(className, content), methodName(methodName) {}
    std::string getSimpleMessage() const override
    {
        return "[MethodCallException] " + name + (methodName.empty() ? "" : ("." + methodName));
    }
    std::string getFormattedMessage() const override
    {
        return "MethodCallException (" + name + (methodName.empty() ? "" : ("." + methodName)) + "): " + content;
    }
};

// Shape 类（基类）
class Shape
{
public:
    virtual ~Shape() {}
};

// Cycle 类
class Cycle : public Shape
{
private:
    int x, y, r;
    std::map<std::string, std::function<int(int)>> methods;

public:
    Cycle(int x, int y, int r) : x(x), y(y), r(r)
    {
        if (r <= 0)
            throw ClassException("Cycle", "fail to init, radius must be a positive number.");
    }
    void registerMethod(std::string s, std::function<int(int)> f)
    {
        if (methods.find(s) != methods.end())
            throw ClassException("Cycle", "method " + s + " already exists.");
        methods[s] = f;
    }
    int operator()(std::string s, int para)
    {
        if (methods.find(s) == methods.end())
            throw MethodCallException("Cycle", "", "method " + s + " not found.");
        try
        {
            return methods[s](para);
        }
        catch (Exception &e)
        {
            throw MethodCallException("Cycle", s, e.what());
        }
    }
};

// Rectangle 类
class Rectangle : public Shape
{
private:
    int x, y, w, h;
    std::map<std::string, std::function<int(int)>> methods;

public:
    Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h)
    {
        if (w <= 0 || h <= 0)
            throw ClassException("Rectangle", "fail to init, width and height must be positive numbers.");
    }
    void registerMethod(std::string s, std::function<int(int)> f)
    {
        if (methods.find(s) != methods.end())
            throw ClassException("Rectangle", "method " + s + " already exists.");
        methods[s] = f;
    }
    int operator()(std::string s, int para)
    {
        if (methods.find(s) == methods.end())
            throw MethodCallException("Rectangle", "", "method " + s + " not found.");
        try
        {
            return methods[s](para);
        }
        catch (Exception &e)
        {
            throw MethodCallException("Rectangle", s, e.what());
        }
    }
};

// 全局函数 printe
void printe(const char *formatter, ...)
{
    va_list args;
    va_start(args, formatter);
    const char *format = formatter;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 's')
            {
                Exception *e = va_arg(args, Exception *);
                std::cout << e->getSimpleMessage();
            }
            else if (*format == 'f')
            {
                Exception *e = va_arg(args, Exception *);
                std::cout << e->getFormattedMessage();
            }
            format++;
        }
        else
        {
            std::cout << *format;
            format++;
        }
    }
}

#endif // EXCEPTION_H