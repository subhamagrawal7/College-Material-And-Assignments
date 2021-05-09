<?xml version = "1.0" encoding = "UTF-8" ?>
<xsl:stylesheet version = "1.0"
xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">
   <xsl:template match = "/">
      <html>
         <body>
            <h2>Employee</h2>
            <table border = "1">
               <tr bgcolor = "pink">
                  <th>ID</th>
                  <th>First Name</th>
                  <th>Last Name</th>
                  <th>Nick Name</th>
                  <th>Salary</th>
               </tr>
               <xsl:for-each select = "class/employee">
               <xsl:sort select = "firstname" order="descending"/>   <!--  order="descending attribute -->
                     <tr>
                     <td><xsl:value-of select = "@id"/></td>
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
