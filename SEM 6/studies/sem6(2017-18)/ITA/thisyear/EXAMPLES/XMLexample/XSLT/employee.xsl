<?xml version = "1.0" encoding = "UTF-8"?>  
<!-- xsl stylesheet declaration with xsl namespace:   
Namespace tells the xlst processor about which   
element is to be processed and which is used for output purpose only   
-->   
<xsl:stylesheet version = "1.0"   
xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">     
<!-- xsl template declaration:    
template tells the xlst processor about the section of xml   
document which is to be formatted. It takes an XPath expression.   
In our case, it is matching document root element and will   
tell processor to process the entire document with this template.   
-->   
   <xsl:template match = "/">   
      <!-- HTML tags   
         Used for formatting purpose. Processor will skip them and browser   
            will simply render them.   
      -->   
      <html>   
         <body>  
            <h2>Employee</h2>   
            <table border = "1">   
               <tr bgcolor = "#9acd32">   
                  <th>ID</th>   
                  <th>First Name</th>   
                  <th>Last Name</th>   
                  <th>Nick Name</th>   
                  <th>Salary</th>   
               </tr>   
               <!-- for-each processing instruction   
               Looks for each element matching the XPath expression   
               -->   
              <xsl:for-each select="class/employee">   
                  <tr>   
                     <td>   
                        <!-- value-of processing instruction   
                        process the value of the element matching the XPath expression   
                        -->   
                        <xsl:value-of select = "@id"/>   
                     </td>   
                     <td><xsl:value-of select = "firstname"/></td>   
                     <td><xsl:value-of select = "lastname"/></td>   
                     <td><xsl:value-of select = "nickname"/></td>   
                     <td><xsl:value-of select = "salary"/></td>     
                  </tr>   
               </xsl:for-each>   
            </table>   
         </body>   
      </html>   
   </xsl:template>    
</xsl:stylesheet>