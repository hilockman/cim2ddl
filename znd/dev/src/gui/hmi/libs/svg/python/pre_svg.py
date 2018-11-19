# -*- coding=utf-8 -*-
import os
import os.path
import re
import xml.etree.ElementTree as ET
from xml.etree.ElementTree import ElementTree,Element

ET.register_namespace('',"http://www.w3.org/2000/svg")
ET.register_namespace('cge',"http://iec.ch/TC57/2005/SVG-schema#")
ET.register_namespace('xlink',"http://www.w3.org/1999/xlink")
ET.register_namespace('cim',"http://iec.ch/TC57/2003/CIM-schema-cim10#")
ET.register_namespace('DF8003',"http://DF8003.com/SVGEX-schema#")
ET.register_namespace('rdf',"http://www.w3.org/1999/02/22-rdf-syntax-ns#")

def read_xml(in_path):  
    '''''读取并解析xml文件 
       in_path: xml路径 
       return: ElementTree'''
    #tree = ElementTree()
    #tree.parse(in_path)
    tree=ET.parse(in_path)
    return tree  
  
def write_xml(tree, out_path):  
    '''''将xml文件写出 
       tree: xml树 
       out_path: 写出路径'''  
    tree.write(out_path, "utf-8",True)  
  
def if_match(node, kv_map):  
    '''''判断某个节点是否包含所有传入参数属性 
       node: 节点 
       kv_map: 属性及属性值组成的map'''  
    for key in kv_map:
        #print ""+str(node.get(key))+" != "+ kv_map.get(key)
        if node.get(key) != kv_map.get(key):  
            return False  
    return True  
  
#---------------search -----  
  
def find_nodes(tree, path):  
    '''''查找某个路径匹配的所有节点 
       tree: xml树 
       path: 节点路径'''  
    return tree.findall(path)  
  
  
def get_node_by_keyvalue(nodelist, kv_map):  
    '''''根据属性及属性值定位符合的节点，返回节点 
       nodelist: 节点列表 
       kv_map: 匹配属性及属性值map'''  
    result_nodes = []  
    for node in nodelist:  
        if if_match(node, kv_map):  
            result_nodes.append(node)  
    return result_nodes  
  
#---------------change -----  
  
def change_node_properties(nodelist, kv_map, is_delete=False,is_add=False):  
    '''''修改/增加 /删除 节点的属性及属性值 
       nodelist: 节点列表 
       kv_map:属性及属性值map'''  
    for node in nodelist:
        #print "change tag--"+node.tag
        #print "key---"+"--".join(node.attrib.keys())
        for key in kv_map:  
            if is_delete:   
                if key in node.attrib:  
                    del node.attrib[key]  
            elif is_add:
                node.set(key, kv_map.get(key))
            elif key in node.attrib:
                #print "change----"+key+"---"+kv_map.get(key)
                node.set(key, kv_map.get(key)) 
              
def change_node_text(nodelist, text, is_add=False, is_delete=False):  
    '''''改变/增加/删除一个节点的文本 
       nodelist:节点列表 
       text : 更新后的文本'''  
    for node in nodelist:  
        if is_add:  
            node.text += text  
        elif is_delete:  
            node.text = ""  
        else:  
            node.text = text  
              
def create_node(tag, property_map, content):  
    '''''新造一个节点 
       tag:节点标签 
       property_map:属性及属性值map 
       content: 节点闭合标签里的文本内容 
       return 新节点'''  
    element = Element(tag, property_map)  
    element.text = content  
    return element  
          
def add_child_node(nodelist, element):  
    '''''给一个节点添加子节点 
       nodelist: 节点列表 
       element: 子节点'''  
    for node in nodelist:  
        node.append(element)  
          
def del_node_by_tagkeyvalue(nodelist, tag, kv_map):  
    '''''同过属性及属性值定位一个节点，并删除之 
       nodelist: 父节点列表 
       tag:子节点标签 
       kv_map: 属性及属性值列表'''  
    for parent_node in nodelist:  
        children = parent_node.getchildren()  
        for child in children:  
            if child.tag == tag and if_match(child, kv_map):  
                parent_node.remove(child)
  
def del_node_by_tagkey(nodelist, tag, key):  
    '''''通过包含某属性定位一个节点，并删除之 
       nodelist: 父节点列表 
       tag:子节点标签 
       kv_map: 属性名'''  
    for parent_node in nodelist:  
        children = parent_node.getchildren()
        i = 0
        for child in children:
            if 'g' in child.tag:
                val = child.get(key,"")
                #print "key--"+val
                if  val and val !="":
                    i=i+1
                    parent_node.remove(child)
        #print "del num--"+str(i)
  
                                        
if __name__ == "__main__":
    rootdir = "D:/svn/cs_platform/UTF8/smartsys_pg/modelfile/org/dms"
    for parent,dirnames,filenames in os.walk(rootdir):
        for filename in filenames:
            if filename[-4:]=='.svg':
                fn=os.path.join(parent,filename)
                #print fn
                tree = read_xml(fn)
                root = tree.getroot()
                #print "root::::"+root.tag
                for child0 in root:
                    #print "child0.tag::::"+child0.tag
                    if 'g' in child0.tag:
                        gid = child0.get('id',"")
                        if "whole_graph" in gid:
                            # ems开关手车处理
                            for child in child0:
                                #print "child--"+child.get('id',"")
                                if child.get('id',"")=='CarBreaker_Layer':
                                    del_node_by_tagkey(child.getchildren(), "g", "break-id")
                                    for cb in child:
                                        for symbol in cb:
                                            for use in symbol:
                                                key = "{http://www.w3.org/1999/xlink}href"
                                                linkS = use.get(key,"")
                                                if linkS == "#breaker2:b:shape0-0":
                                                    use.set(key, "#breaker:shape6-0")
                                                elif linkS == "#breaker2:b:shape4-0":
                                                    use.set(key, "#breaker:shape4-0")
                        elif "Text_Layer" in gid:
                            for child in child0:
                                textId = child.get('id',"")
                                psrAttr = {}
                                measureId = textId.split('-')[1]
                                idmap = {}
                                idmap["id"]=measureId;
                                for mchild0 in root:
                                    if 'g' in mchild0.tag:
                                        mgid = mchild0.get('id',"")
                                        if "Measurement_Layer" in mgid:
                                            measureNode = get_node_by_keyvalue(mchild0.getchildren(),idmap)
                                            #print "----measureNode----"+str(len(measureNode))
                                            if len(measureNode)>0:
                                                for meta in measureNode[0]:
                                                    for cge in meta:
                                                        #print "----cge----"+cge.tag
                                                        if "PSR_Ref" in cge.tag:
                                                            psrAttr = cge.attrib
                                                            #print "--------".join(psrAttr.keys())
                                                            break
                                if len(psrAttr.keys()) > 0:
                                    for txtMeta in child:
                                        for txtCge in txtMeta:
                                            if "PSR_Ref" in txtCge.tag:
                                                change_node_properties([txtCge],psrAttr,False,True);                                                
                write_xml(tree, fn)
                print "update "+fn+" ok"
