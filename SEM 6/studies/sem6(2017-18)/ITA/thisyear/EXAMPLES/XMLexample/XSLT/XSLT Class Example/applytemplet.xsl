<?xml version = "1.0" encoding = "UTF-8"?> 
<xsl:stylesheet version = "1.0" 
   xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">   
   <xsl:template match = "/"> 
      <html> 
         <body> 
            <h2>Students</h2> 
            <xsl:apply-templates select = "class/student" /> 
         </body> 
      </html> 
   </xsl:template>  

   <xsl:template match = "class/student"> 
      <xsl:apply-templates select = "@rollno" /> 
      <xsl:apply-templates select = "firstname" /> 
      <xsl:apply-templates select = "lastname" /> 
      <xsl:apply-templates select = "nickname" /> 
      <xsl:apply-templates select = "marks" /> 
      <br /> 
   </xsl:template>  
   
<!-- xsl:value-of uses the select attribute to choose elements. 
     Because we are already at the correct element, student, we use a period "." to select the current element's data. 
     The period is a special character to use when you want to select the same element that you matched with template's match attribute.-->

   <xsl:template match = "@rollno"> 
      <span style = "font-size = 22px;"> 
         <xsl:value-of select = "." /> 
      </span> 
      <br /> 
   </xsl:template>  

   <xsl:template match = "firstname"> 
      First Name:<span style = "color:blue;"> 
         <xsl:value-of select = "." /> 
      </span> 
      <br /> 
   </xsl:template>  

   <xsl:template match = "lastname"> 
      Last Name:<span style = "color:green;"> 
         <xsl:value-of select = "." /> 
      </span> 
      <br /> 
   </xsl:template>  

   <xsl:template match = "nickname"> 
      Nick Name:<span style = "color:red;"> 
         <xsl:value-of select = "." /> 
      </span> 
      <br /> 
   </xsl:template>  

   <xsl:template match = "marks"> 
      Marks:<span style = "color:gray;"> 
         <xsl:value-of select = "." /> 
      </span> 
      <br /> 
   </xsl:template>  
	
</xsl:stylesheet>