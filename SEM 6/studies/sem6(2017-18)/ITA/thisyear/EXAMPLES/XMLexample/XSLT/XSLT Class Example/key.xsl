<xsl:stylesheet version = "1.0"   
   xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">   
   <xsl:key name = "lastname-search" match = "employee" use = "lastname"/>    
   <xsl:template match = "/">    
      <html>    
         <body>   
            <h2> Employee</h2>    
            <table border = "1">    
               <tr bgcolor = "pink">    
                  <th> ID</th>   
                  <th> First Name</th>   
                  <th> Last Name</th>    
                  <th> Nick Name</th>    
                  <th> Salary</th>    
               </tr>    
       
	   <!-- specify a named name-value pair assigned to a specific element in an XML document -->
               <xsl:for-each select = "key('lastname-search', 'Symon')">    
      
                  <tr>   
                     <td> <xsl:value-of select = "@id"/> </td>    
                     <td> <xsl:value-of select = "firstname"/> </td>    
                     <td> <xsl:value-of select = "lastname"/> </td>    
                     <td> <xsl:value-of select = "nickname"/> </td>    
                     <td> <xsl:value-of select = "salary"/> </td>    
                  </tr>    
       
               </xsl:for-each>    
            </table>    
        </body>    
      </html>    
   </xsl:template>     
</xsl:stylesheet>   