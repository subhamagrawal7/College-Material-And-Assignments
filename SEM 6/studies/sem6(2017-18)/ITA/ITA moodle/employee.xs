<?xml version="1.0"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema" >

<xs:element name="Employee_Info" type="EmployeeInfoType" />
<xs:complexType name="EmployeeInfoType">
<xs:sequence>
  <xs:element ref="Employee" minOccurs="0" maxOccurs="unbounded" />
 </xs:sequence>
</xs:complexType>

 <xs:element name="Employee" type="EmployeeType" />
 <xs:complexType name="EmployeeType">
  <xs:sequence >
   <xs:element ref="Name" />
   <xs:element ref="Department" />
   <xs:element ref="Telephone" />
  <xs:element ref="Email" />
  </xs:sequence>
 <xs:attribute name="Employee_Number" type="xs:int" use="required"/>
 </xs:complexType>

 <xs:element name="Name" type="xs:string" />
 <xs:element name="Department" type="xs:string" />
 <xs:element name="Telephone" type="xs:string" />
 <xs:element name="Email" type="xs:string" />

 </xs:schema>