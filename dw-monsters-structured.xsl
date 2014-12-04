<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    version="1.0" xmlns:aid="http://ns.adobe.com/AdobeInDesign/4.0/"
    xmlns:func="http://exslt.org/functions"
    xmlns:exsl="http://exslt.org/common"
    xmlns:str="http://exslt.org/strings"
    extension-element-prefixes="str func exsl">
    
    <xsl:output indent="yes"/>
    
    <xsl:template match="/">
        <monsters>
            <xsl:for-each select="files/file">
                <xsl:apply-templates select="document(.)/Root"></xsl:apply-templates>
            </xsl:for-each>
        </monsters>
    </xsl:template>
    
    <xsl:template match="Root">
        <xsl:variable name="setting"><xsl:value-of select="h1"/></xsl:variable>
        <xsl:for-each select="Body/p[@aid:pstyle='MonsterName']">
            <monster>
                <name><xsl:value-of select="normalize-space(text())"/></name>
                <tags>
                    <xsl:for-each select="str:tokenize(span,',')">
                        <tag><xsl:value-of select="normalize-space(.)"/></tag>
                    </xsl:for-each>
                </tags>
                <setting><xsl:value-of select="$setting"/></setting>
                <stats>
                    <xsl:for-each select="str:tokenize(following-sibling::p[@aid:pstyle='MonsterStats']/text(),')P')">
                        <xsl:choose>
                            <xsl:when test="position()=1">
                                <attack><xsl:value-of select="normalize-space(.)"/>)</attack>
                            </xsl:when>
                            <xsl:when test="position()=2">
                                <hp><xsl:value-of select="normalize-space(.)"/>P</hp>
                            </xsl:when>
                            <xsl:when test="position()=3">
                                <armor><xsl:value-of select="normalize-space(.)"/></armor>
                            </xsl:when>
                        </xsl:choose>
                        
                    </xsl:for-each>
                    <xsl:for-each select="str:tokenize(following-sibling::p[@aid:pstyle='MonsterStats']/span[@aid:cstyle='Tags'],',')">
                        <tag><xsl:value-of select="normalize-space(.)"/></tag>
                    </xsl:for-each>
                </stats>
                
                <qualities><xsl:value-of select="normalize-space(following-sibling::p[@aid:pstyle='MonsterQualities']/text())"/></qualities>
                <description><xsl:value-of select="normalize-space(following-sibling::p[@aid:pstyle='MonsterDescription']/text())"/></description>
                <instinct><xsl:value-of select="substring(normalize-space(following-sibling::p[@aid:pstyle='MonsterDescription']/text()[preceding-sibling::em[position()=last()]]),3)"/></instinct>
                <moves>
                    <xsl:for-each select="following-sibling::ul[1]/li">
                        <move><xsl:value-of select="."/></move>
                    </xsl:for-each>
                </moves>
            </monster>
        </xsl:for-each>
        
    </xsl:template>
    
    <func:function name="str:tokenize">
        <xsl:param name="string" select="''" />
        <xsl:param name="delimiters" select="' &#x9;&#xA;'" />
        <xsl:choose>
            <xsl:when test="not($string)">
                <func:result select="/.." />
            </xsl:when>
            <xsl:when test="not(function-available('exsl:node-set'))">
                <xsl:message terminate="yes">
                    ERROR: EXSLT - Functions implementation of str:tokenize relies on exsl:node-set().
                </xsl:message>
            </xsl:when>
            <xsl:otherwise>
                <xsl:variable name="tokens">
                    <xsl:choose>
                        <xsl:when test="not($delimiters)">
                            <xsl:call-template name="str:_tokenize-characters">
                                <xsl:with-param name="string" select="$string" />
                            </xsl:call-template>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:call-template name="str:_tokenize-delimiters">
                                <xsl:with-param name="string" select="$string" />
                                <xsl:with-param name="delimiters" select="$delimiters" />
                            </xsl:call-template>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:variable>
                <func:result select="exsl:node-set($tokens)/token" />
            </xsl:otherwise>
        </xsl:choose>
    </func:function>
    
    <xsl:template name="str:_tokenize-characters">
        <xsl:param name="string" />
        <xsl:if test="$string">
            <token><xsl:value-of select="substring($string, 1, 1)" /></token>
            <xsl:call-template name="str:_tokenize-characters">
                <xsl:with-param name="string" select="substring($string, 2)" />
            </xsl:call-template>
        </xsl:if>
    </xsl:template>
    
    <xsl:template name="str:_tokenize-delimiters">
        <xsl:param name="string" />
        <xsl:param name="delimiters" />
        <xsl:variable name="delimiter" select="substring($delimiters, 1, 1)" />
        <xsl:choose>
            <xsl:when test="not($delimiter)">
                <token><xsl:value-of select="$string" /></token>
            </xsl:when>
            <xsl:when test="contains($string, $delimiter)">
                <xsl:if test="not(starts-with($string, $delimiter))">
                    <xsl:call-template name="str:_tokenize-delimiters">
                        <xsl:with-param name="string" select="substring-before($string, $delimiter)" />
                        <xsl:with-param name="delimiters" select="substring($delimiters, 2)" />
                    </xsl:call-template>
                </xsl:if>
                <xsl:call-template name="str:_tokenize-delimiters">
                    <xsl:with-param name="string" select="substring-after($string, $delimiter)" />
                    <xsl:with-param name="delimiters" select="$delimiters" />
                </xsl:call-template>
            </xsl:when>
            <xsl:otherwise>
                <xsl:call-template name="str:_tokenize-delimiters">
                    <xsl:with-param name="string" select="$string" />
                    <xsl:with-param name="delimiters" select="substring($delimiters, 2)" />
                </xsl:call-template>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
    
</xsl:stylesheet>