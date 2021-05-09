<?xml version = "1.0" encoding = "UTF-8"?> 
<xsl:stylesheet version = "1.0" 
   xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">   
   <xsl:template match = "/"> 
      <html> 
         <body> 
            <h2>Students</h2> 
            <table border = "1"> 
               <tr bgcolor = "#9acd32"> 
                  <th>Roll No</th> 
                  <th>First Name</th> 
                  <th>Last Name</th> 
                  <th>Nick Name</th> 
                  <th>Marks</th> 
                  <th>Grade</th> 
               </tr> 
					
               <xsl:for-each select = "class/student"> 
					
                  <tr> 
                     <td><xsl:value-of select = "@rollno"/></td> 
                     <td><xsl:value-of select = "firstname"/></td> 
                     <td><xsl:value-of select = "lastname"/></td> 
                     <td><xsl:value-of select = "nickname"/></td> 
                     <td><xsl:value-of select = "marks"/></td> 
							
                     <td> 
                        <xsl:choose> 
                           <xsl:when test = "marks > 90"> 
                              High 
                           </xsl:when> 
									
                           <xsl:when test = "marks > 85"> 
                              Medium 
                           </xsl:when> 
									
                           <xsl:otherwise> 
                              Low 
                           </xsl:otherwise> 
                        </xsl:choose> 
                     </td> 
                  </tr> 
               </xsl:for-each> 
            </table> 
         </body> 
      </html> 
   </xsl:template>  
</xsl:stylesheet>