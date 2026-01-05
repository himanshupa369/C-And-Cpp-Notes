
<h3> Extra Topic: <br> upcast,downcast,RTTI,mutable and volatile keyword  </h3>
<h1>Run-Time Type Identification (RTTI)</h1>
<p><br>Run-Time Type Identification (RTTI) is a feature in C++ that allows you to obtain the type information of an object during program execution. This can be useful when using dynamic typing, where the type of an object can change at runtime.<br></p>
<h5>There are two main mechanisms for RTTI in C++:<br></h5>
<list><li>typeid operator</li>
<li>dynamic_cast operator</li></list>

<h4>typeid operator:</h4>
<p>typeid is an operator that returns a reference to an object of type std::type_info, which contains information about the type of the object. The header file <typeinfo> should be included to use typeid.</p>

<h4>dynamic_cast operator</h4>
<p>dynamic_cast is a type-casting operator that performs a runtime type check and safely downcasts a base pointer or reference to a derived pointer or reference. It returns null or throws a bad_cast exception (if casting references) when the casting fails.</p>
