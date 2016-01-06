package com.example.multimedia.hello;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

public class NewActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_new);
    }

    public void onBackButtonClicked(View v) {
        Toast.makeText(getApplicationContext(), "돌아가기 버튼이 눌렸어요", Toast.LENGTH_LONG).show();
        finish();
    }

}
