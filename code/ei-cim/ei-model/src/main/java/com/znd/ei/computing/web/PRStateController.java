package com.znd.ei.computing.web;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.ZhongND.memdb.JMemDBApi;
import com.ZhongND.memdb.MDBDefine;
import com.znd.ei.computing.dao.PRStateRepository;
import com.znd.ei.computing.domain.FState;

@Controller
@RequestMapping(path = "/prstate")
public class PRStateController {
	@Autowired
	private PRStateRepository pRStateRepository;

	 
	@GetMapping(path = "/load")
	// Map ONLY GET Requests
	public @ResponseBody String loadFromMemDB() {
		String dbname = MDBDefine.g_strPRDBEntry;
		System.out.println("dbname:"+dbname);
		JMemDBApi.initMemDB(dbname, 0, 1);
		int nTableIndex = JMemDBApi.getTableIndex(dbname, "抽样状态");
		int num = JMemDBApi.getTableRestrictNum(dbname, nTableIndex);
		System.out.println("tableIndex:" + nTableIndex);
		System.out.println("num:" + num);
		List fileNames = new ArrayList<String>();
		for (int i = 0; i < num; i++)
		{
			int nFieldIndex = JMemDBApi.getTableRestrictField(dbname, nTableIndex, i);
			String sFieldName = JMemDBApi.getFieldDesp(dbname, nTableIndex, nFieldIndex);
			fileNames.add(sFieldName);
			System.out.println(nFieldIndex + ":" + sFieldName);

		}
		int sum = JMemDBApi.getTableRecordNum(dbname, nTableIndex);
//		Class clazz = PRFState.class;
//		clazz.getFields();
//		for (int i = 0; i < sum; i++) {
//			String [] strs = JMemDBApi.getRecordRowValueArray(dbname, nTableIndex, i);
//			PRFState state = new PRFState();
//			
//		}
		
		return "Loaded";
	}

	@GetMapping(path = "/all")
	public @ResponseBody Iterable<FState> getAllComputes() {
		// This returns a JSON or XML with the users
		return pRStateRepository.findAll();
	}
}
